#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> topologicalOrder;
vector<int> visited;
int numVertices, numEdges, hasCycle;

void dfs(int vertex) {
    visited[vertex] = 1;
    for (int i = 0; i < graph[vertex].size(); i++) {
        int neighbor = graph[vertex][i];
        if (visited[neighbor] == 1) hasCycle = 1;
        if (visited[neighbor] == 0) dfs(neighbor);
    }
    visited[vertex] = 2;
    topologicalOrder.push_back(vertex);
}

void topSort() {
    for (int vertex = 1; vertex <= numVertices; vertex++) {
        if (visited[vertex] == 0) {
            dfs(vertex);
        }
    }
}

int main() {
    cin >> numVertices >> numEdges;
    graph.resize(numVertices + 1);
    visited.resize(numVertices + 1);
    for (int i = 0; i < numEdges; i++) {
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
    }
    hasCycle = 0;
    topSort();
    if (hasCycle == 1) {
        cout << "-1" << endl;
    } else {
        for (int i = topologicalOrder.size() - 1; i >= 0; i--) {
            cout << topologicalOrder[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
