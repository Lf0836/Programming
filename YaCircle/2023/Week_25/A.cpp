#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, INF);

    for (int i = 0; i < m; i++) {
        int b, e, w;
        cin >> b >> e >> w;
        graph[b].push_back({e, w});
        graph[e].push_back({b, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    int minWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;
        minWeight += dist[u];

        for (auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!visited[v] && weight < dist[v]) {
                dist[v] = weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << minWeight << endl;

    return 0;
}
