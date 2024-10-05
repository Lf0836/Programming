#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct Edge {
  int dest;
  int company;
};

int bfs(vector<vector<Edge>>& graph, int n) {
  vector<int> cost(n + 1, INT_MAX);
  queue<int> q;
  q.push(1);
  cost[1] = 0;
  while (!q.empty()) {
    int current = q.front();
    q.pop();
    for (const auto& neighbor : graph[current]) {
      int newCost = cost[current] + (neighbor.company != cost[current]);
      if (newCost < cost[neighbor.dest]) {
        cost[neighbor.dest] = newCost;
        q.push(neighbor.dest);
      }
    }
  }
  return cost[n] == INT_MAX ? -1 : cost[n];
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<Edge>> graph(n + 1);
  for (int i = 0; i < m; i++) {
    int p, q, c;
    cin >> p >> q >> c;
    graph[p].push_back({q, c});
    graph[q].push_back({p, c});
  }
  int minCost = bfs(graph, n);
  cout << minCost << endl;
  return 0;
}
