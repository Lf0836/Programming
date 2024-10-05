#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& graph, int vertex, vector<bool>& visited, vector<int>& component) {
    visited[vertex] = true;
    component.push_back(vertex);
    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited, component);
        }
    }
}

void FCC(vector<vector<int>>& graph_matrix, vector<vector<int>>& components) {
    int totalVertices = graph_matrix.size() - 1;
    vector<bool> visited(totalVertices + 1, false);
    for (int vertex = 1; vertex <= totalVertices; vertex++) {
        if (!visited[vertex]) {
            vector<int> component;
            dfs(graph_matrix, vertex, visited, component);
            components.push_back(component);
        }
    }
}

int main() {
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;
    vector<vector<int>> adjacencyList(numVertices + 1), components;
    vector<bool> visited(numVertices + 1, false);
    for (int i = 0; i < numEdges; i++) {
        int a, b;
        cin >> a >> b;
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a);
    }
    FCC(adjacencyList, components);
    cout << components.size() << endl;
    for (vector<int>& component : components) {
        cout << component.size() << endl;
        sort(component.begin(), component.end());
        for (int vertex : component) {
            cout << vertex << " ";
        }
        cout << endl;
    }
    return 0;
}
