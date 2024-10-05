#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<vector<pair <int, int>>>> graph;
vector<vector <int>> dist;

void dfs() {
    queue<pair<int, int>> quePair;
    quePair.push({0, 0});
    dist[0][0] = 0;
    while (!quePair.empty()) {
        pair<int, int> vertea = quePair.front();
        quePair.pop();
        for (auto neighbor : graph[vertea.first][vertea.second]) {
            if (dist[neighbor.first][neighbor.second] == -1) {
                quePair.push(neighbor);
                dist[neighbor.first][neighbor.second] = dist[vertea.first][vertea.second] + 1;
            }
        }
    }
}

int main() {
    int r, el, col, a, b;
    cin >> r >> col;
    vector<vector<int>> table(r, vector <int> (col));
    graph.resize(r, vector<vector<pair<int, int>>> (col));
    dist.resize(r, vector <int> (col, -1));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < col; j++) {
            cin >> el;
            table[i][j] = el;
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < col; j++) {
            if (table[i][j] == 0) {
                if (j+1 < col && table[i][j+1] != 1) {
                    a = i;
                    b = j;
                    while (b < col && table[a][b] == 0) {
                        b++;
                    }
                    if (b == col) {
                        graph[i][j].push_back({a, b-1});
                    } else if (table[a][b] == 2) {
                        graph[i][j].push_back({a, b});
                    } else {
                        graph[i][j].push_back({a, b-1});
                    }
                }
                if (j > 0 && table[i][j-1] != 1) {
                    b = j;
                    a = i;
                    while (b >= 0 && table[a][b] == 0) {
                        b--;
                    }
                    if (b == -1) {
                        graph[i][j].push_back({a, b+1});
                    } else if (table[a][b] == 2) {
                        graph[i][j].push_back({a, b});
                    } else {
                        graph[i][j].push_back({a, b+1});
                    }
                }
                if (i+1 < r && table[i+1][j] != 1) {
                    b = j;
                    a = i;
                    while (a < r && table[a][b] == 0) {
                        a++;
                    }
                    if (a == r) {
                        graph[i][j].push_back({a-1, b});
                    } else if (table[a][b] == 2) {
                        graph[i][j].push_back({a, b});
                    } else {
                        graph[i][j].push_back({a-1, b});
                    }
                }
                if (i > 0 && table[i-1][j] != 1) {
                    b = j;
                    a = i;
                    while (a >= 0 && table[a][b] == 0) {
                        a--;
                    }
                    if (a == -1) {
                        graph[i][j].push_back({a+1, b});
                    } else if (table[a][b] == 2) {
                        graph[i][j].push_back({a, b});
                    } else {
                        graph[i][j].push_back({a+1, b});
                    }
                }
            }
        }
    }
    dfs();
    int ans = 1e9;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < col; j++) {
            if (table[i][j] == 2) {
                if (dist[i][j] < ans && dist[i][j] >= 0) {
                    ans = dist[i][j];
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
