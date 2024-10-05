#include <iostream>
#include <vector>

using namespace std;

struct Label {
    bool visited;
    long long x, y;
};

vector<Label> labels(200000, {false, 0, 0});

struct Edge {
    long long destination, weightX, weightY;
};

void bfs(vector<vector<Edge>>& graph, long long vertex) {
    for (int i = 0; i < graph[vertex].size(); i++) {
        if (!labels[graph[vertex][i].destination].visited) {
            labels[graph[vertex][i].destination].x = labels[vertex].x + graph[vertex][i].weightX;
            labels[graph[vertex][i].destination].y = labels[vertex].y + graph[vertex][i].weightY;
            labels[graph[vertex][i].destination].visited = true;
            bfs(graph, graph[vertex][i].destination);
        }
        labels[graph[vertex][i].destination].visited = true;
    }
}

int main() {
    long long n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n, vector<Edge>(0));

    for (int i = 0; i < m; i++) {
        long long start, end, weightX, weightY;
        cin >> start >> end >> weightX >> weightY;
        start--;
        end--;
        Edge e = {end, weightX, weightY};
        graph[start].push_back(e);
        e = {start, -weightX, -weightY};
        graph[end].push_back(e);
    }

    labels[0].visited = true;
    bfs(graph, 0);

    for (int i = 0; i < n; i++) {
        if (labels[i].visited) {
            cout << labels[i].x << " " << labels[i].y << endl;
        } else {
            cout << "undefined" << endl;
        }
    }
    return 0;
}
