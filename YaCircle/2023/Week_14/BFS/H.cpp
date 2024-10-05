#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
long long n, m;
vector<set<pair<long long, long long>>> g;
vector<long long> dist;
set<pair<long long, long long>> q;

void bfs(long long current) {
    for (auto i : g[current]) {
        if (dist[current] + i.second < dist[i.first]) {
            dist[i.first] = dist[current] + i.second;
            q.insert({dist[i.first], i.first});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("kefir.in", "r", stdin);
    freopen("kefir.out", "w", stdout);
    cin >> n >> m;
    g.resize(n);
    dist.resize(n, INF);
    while (m--) {
        long long x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        g[x].insert({y, c});
        g[y].insert({x, c});
    }
    dist[0] = 0;
    q.insert({0, 0});
    while (!q.empty()) {
        long long top =(*q.begin()).second;
        q.erase(q.begin());
        bfs(top);
    }
    if (dist[n - 1] == INF) {
        cout << -1;
    } else {
        cout << dist[n - 1];
    }
    return 0;
}
