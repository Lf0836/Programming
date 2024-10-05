#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <climits>

using namespace std;

long long n, m, st, t, tst, wbw, mid, cis = 1440;
vector <long long> res;
vector <vector<vector<long long>>> graph;

void JD(long long st) {
    res.clear();
    res.resize(n + 1, INT_MAX);
    res[st] = 0;
    priority_queue <pair <long long, long long>, vector <pair <long long, long long>>, greater <pair <long long, long long>>> pr;
    pr.push({0, st});
    while (!pr.empty()) {
        long long vap = pr.top().second;
        pr.pop();
        for (int ind = 0; ind < int(graph[vap].size()); ind++) {
            long long s = graph[vap][ind][0];
            if (graph[vap][ind][2] >= 3000000 + mid * 100 && res[s] > res[vap] + graph[vap][ind][1]) {
                res[s] = res[vap] + graph[vap][ind][1];
                pr.push(make_pair(res[s], s));
            }
        }
    }
}

int main() {
    cin >> n >> m;
    if (n == 1) {
        cout << 10000000 << endl;
        return 0;
    }
    graph.resize(n + 1);
    for (long long i = 0; i < m; ++i) {
        cin >> st >> t >> tst >> wbw;
        --st; --t;
        vector <long long> current;
        current.push_back(t);
        current.push_back(tst);
        current.push_back(wbw);
        graph[st].push_back(current);
        current[0] = st;
        graph[t].push_back(current);
    }
    long long l = 0, r = 1e9 + 1;
    while (r - l > 1) {
        mid = (r + l) / 2;
        JD(0);
        if (res[n - 1] > cis) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << l << endl;
    return 0;
}
