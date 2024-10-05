#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
  int V;
  list<int>* adj;
  void DFSUtil(int v, bool visited[], int& path_count);

 public:
  Graph(int V);
  void addEdge(int v, int w);
  int countPathsThroughEdge(int edgeIndex);
};

Graph::Graph(int V) {
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
  adj[w].push_back(v);
}

void Graph::DFSUtil(int v, bool visited[], int& path_count) {
  visited[v] = true;
  path_count++;
  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i) {
    if (!visited[*i]) {
      DFSUtil(*i, visited, path_count);
    }
  }
  visited[v] = false;
}

int Graph::countPathsThroughEdge(int edgeIndex) {
  int path_count = 0;
  bool* visited = new bool[V];
  for (int i = 0; i < V; i++) visited[i] = false;
  int v = edgeIndex / V;
  int w = edgeIndex % V;
  adj[v].remove(w);
  adj[w].remove(v);
  DFSUtil(v, visited, path_count);
  adj[v].push_back(w);
  adj[w].push_back(v);
  return path_count;
}

int main() {
  int N, M;
  cin >> N >> M;
  Graph g(N);
  for (int i = 0; i < M; i++) {
    int v, u;
    cin >> v >> u;
    g.addEdge(v - 1, u - 1);
  }
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int e;
    cin >> e;
    cout << g.countPathsThroughEdge(e - 1) << endl;
  }
  return 0;
}
