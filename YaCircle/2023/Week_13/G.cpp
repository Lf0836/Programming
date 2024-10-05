#include <iostream>
#include <list>

using namespace std;

bool isBipartite(short v, list<short>* graph, short* colors, short color) {
    colors[v] = color;
    for (short next : graph[v]) {
        if (colors[next] == 0) {
            if (!isBipartite(next, graph, colors, (color == 2) ? 1 : 2)) {
                return false;
            }
        } else if (colors[next] == color) {
            return false;
        }
    }
    return true;
}

bool checkBipartiteGraph(short N, short M, list<short>* graph) {
    short colors[N];
    for (short i = 0; i < N; i++) {
        colors[i] = 0;
    }
    for (short i = 0; i < N; i++) {
        if (colors[i] == 0) {
            if (!isBipartite(i, graph, colors, 1)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    short numVertices, numEdges, vertex1, vertex2;
    cin >> numVertices >> numEdges;
    list<short> graph[numVertices];
    for (short i = 0; i < numEdges; i++) {
        cin >> vertex1 >> vertex2;
        vertex1--;
        vertex2--;
        graph[vertex1].push_back(vertex2);
        graph[vertex2].push_back(vertex1);
    }
    bool isBipartiteGraph = checkBipartiteGraph(numVertices, numEdges, graph);
    if (isBipartiteGraph) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}