#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& adj_list, int node, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj_list[node]) {
        if (!visited[neighbor]) {
            dfs(adj_list, neighbor, visited);
        }
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;
    if (vertices != edges + 1) {
        cout << "NO" << endl;
        return 0;
    }
    vector<vector<int>> adjacency_list(vertices);
    for (int i = 0; i < edges; ++i) {
        int from, to;
        cin >> from >> to;
        adjacency_list[from - 1].push_back(to - 1);
        adjacency_list[to - 1].push_back(from - 1);
    }
    vector<bool> visited(vertices, false);
    int connected_components = 0;
    for (size_t i = 0; i < adjacency_list.size(); ++i) {
        if (!visited[i]) {
            dfs(adjacency_list, i, visited);
            connected_components++;
        }
    }
    if (connected_components != 1) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}