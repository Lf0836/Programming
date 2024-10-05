#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int const MAX_N = 1001;

int n, x;
int g[MAX_N][MAX_N];
int dist[MAX_N];

void bfs(int start) {
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to = 1; to <= n; to++) {
            if (g[v][to] == 1 && dist[to] == -1) {
                q.push(to);
                dist[to] = dist[v] + 1;
            }
        }
    }
}

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i + 1][j + 1];
        }
    }
    memset(dist, -1, sizeof(dist));
    bfs(x);
    for (int i = 0; i < n; i++) {
        cout << dist[i + 1] << " ";
    }
    cout << '\n';
    return 0;
}
