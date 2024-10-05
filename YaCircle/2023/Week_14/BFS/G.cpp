#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m;
vector<string> grid;
vector<vector<bool>> visited;

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int count = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto [cx, cy] = q.front();
            q.pop();

            for (int j = 0; j < 4; j++) {
                int nx = cx + dx[j];
                int ny = cy + dy[j];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] == '.') {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    count++;
                }
            }
        }
    }

    return count;
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int maxCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != '.' && !visited[i][j]) {
                maxCount = max(maxCount, bfs(i, j));
            }
        }
    }

    cout << maxCount << endl;
    return 0;
}
