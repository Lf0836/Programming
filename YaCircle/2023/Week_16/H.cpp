#include <iostream>
#include <vector>

#define INF 1e10l

using namespace std;

struct change_name { long long first_name, last_name, third_name; };
vector<pair<long long, long long>> gp[2002];
vector<change_name> g;
vector<long long> d(2002, -INF), p(2002, -1), used(2002, 0), ban(2002, 0);

void new_bfs(long long i, long long c) {
    used[i] = c;
    for (auto& e : gp[i]) {
        if (!used[e.first]) new_bfs(e.first, c);
    }
}

void modify() {
    long long n, m;
    cin >> n >> m;

    for (long long i = 0; i < m; i++) {
        change_name ins;
        cin >> ins.first_name >> ins.last_name >> ins.third_name;
        ins.first_name--; ins.last_name--;
        gp[ins.last_name].push_back(make_pair(ins.first_name, ins.third_name));
        g.push_back(ins);
    }
    d[0] = 0;
    for (long long k = 0; k < n; k++) {
        for (auto& e : g) {
            if (d[e.first_name] > -INF && d[e.last_name] < d[e.first_name] + e.third_name) {
                d[e.last_name] = d[e.first_name] + e.third_name;
                p[e.last_name] = e.first_name;
            }
        }
    }
    if (d[n - 1] == -INF) {
        cout << ":(";
        return;
    }
    new_bfs(n - 1, 1);

    long long u = 2002;
    while (u != -1) {
        u = -1;
        for (auto& e : g) {
            if (!ban[e.first_name] && !ban[e.last_name]) {
                if (d[e.first_name] > -INF && d[e.last_name] < d[e.first_name] + e.third_name) {
                    d[e.last_name] = d[e.first_name] + e.third_name;
                    p[e.last_name] = e.first_name;
                    u = e.first_name;
                }
            }
        }
        if (u == -1) continue;
        vector<long long> cyc;
        long long y = u;
        for (long long i = 0; i < n; i++) {
            y = p[y];
        }
        for (long long cur = y;; cur = p[cur]) {
            cyc.push_back(cur);
            if (cur == y && cyc.size() > 1) break;
        }
        for (auto b : cyc) ban[b] = 1;
    }

    for (long long i = 0; i < n; i++) {
        if (used[i] && ban[i]) {
            cout << ":)";
            return;
        }
    }
    cout << d[n - 1];
}

int main() {
    modify();
    return 0;
}