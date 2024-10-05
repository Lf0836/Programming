#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int n, x, y, k, u, v, initial_x, initial_y, final_x, final_y;
    queue<pair<int, int>> q;
    vector<vector<int>> parent;
    int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2},
        dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
    cin >> n;
    parent.resize(n + 1, vector<int>(n + 1, -1));
    int dist[n + 1][n + 1];
    for (x = 0; x <= n; ++x)
        for (y = 0; y <= n; ++y)
            dist[x][y] = 1000000000;
    cin >> initial_x >> initial_y >> final_x >> final_y;
    dist[initial_x][initial_y] = 0;
    q.push(make_pair(initial_x, initial_y));
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (k = 0; k < 8; ++k) {
            u = x + dx[k];
            v = y + dy[k];
            if (u > 0 && u <= n && v > 0 && v <= n && dist[u][v] > dist[x][y] + 1) {
                dist[u][v] = dist[x][y] + 1;
                parent[u][v] = x * (n + 1) + y;
                q.push(make_pair(u, v));
            }
        }
    }
    cout << dist[final_x][final_y] << endl;
    vector<pair<int, int>> path;
    int cur_x = final_x, cur_y = final_y;
    while (cur_x != initial_x || cur_y != initial_y) {
        path.push_back(make_pair(cur_x, cur_y));
        int temp = parent[cur_x][cur_y];
        cur_x = temp / (n + 1);
        cur_y = temp % (n + 1);
    }
    path.push_back(make_pair(initial_x, initial_y));
    reverse(path.begin(), path.end());
    for (auto coord : path) {
        cout << coord.first << " " << coord.second << endl;
    }
    return 0;
}
