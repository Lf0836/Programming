#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;
vector<int> edgeStability;

int dfs(int u, int p) {
  int paths = 1;
  for (int v : adj[u]) {
    if (v != p) {
      int subpaths = dfs(v, u);
      edgeStability.push_back(subpaths * (adj.size() - subpaths));
      paths += subpaths;
    }
  }
  return paths;
}

int main() {
  int N, M;
  cin >> N >> M;

  adj.resize(N + 1);
  visited.resize(N + 1, 0);

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, -1);

  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int e;
    cin >> e;
    cout << edgeStability[e - 1] << endl;
  }

  return 0;
}