#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& graph, int vertex, vector<vector<bool>>& visited, int columns) {
    visited[vertex / columns][vertex % columns] = true;
    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor / columns][neighbor % columns]) {
            dfs(graph, neighbor, visited, columns);
        }
    }
}

int main() {
    int rows, columns;
    cin >> rows >> columns;
    vector<vector<char>> grid(rows, vector<char>(columns));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> adjacencyList(rows * columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if ((j < columns - 1) && (grid[i][j] == '#' && grid[i][j + 1] == '#')) {
                adjacencyList[i * columns + j].push_back(i * columns + j + 1);
                adjacencyList[i * columns + j + 1].push_back(i * columns + j);
            }
            if ((i < rows - 1) && (grid[i][j] == '#' && grid[i + 1][j] == '#')) {
                adjacencyList[i * columns + j].push_back((i + 1) * columns + j);
                adjacencyList[(i + 1) * columns + j].push_back(i * columns + j);
            }
        }
    }

    vector<vector<bool>> visited(rows, vector<bool>(columns, false));
    int componentCount = 0;
    for (int i = 0; i < rows * columns; i++) {
        if (!visited[i / columns][i % columns] && grid[i / columns][i % columns] == '#') {
            dfs(adjacencyList, i, visited, columns);
            componentCount++;
        }
    }

    cout << componentCount << endl;
    return 0;
}
