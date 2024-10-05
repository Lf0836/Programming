#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<long long> dist;
vector<long long> pred;
void dxra(int start, int num_nodes) {
  dist[start] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, start});
  while (!pq.empty()) {
    auto [dist_curr, ver] = pq.top();
    pq.pop();
    if (dist_curr > dist[ver]) {
      continue;
    }
    for (auto [adjacent, weight] : graph[ver]) {
      if (dist[adjacent] > dist[ver] + weight) {
        dist[adjacent] = dist[ver] + weight;
        pq.push({dist[adjacent], adjacent});
        pred[adjacent] = ver;
      }
    }
  }
}

int main() {
  ifstream input_file("dist.in");
  ofstream output_file("dist.out");
  int num_nodes, num_edges, start, end, node1, node2, weight;
  input_file >> num_nodes >> num_edges >> start >> end;
  dist.resize(num_nodes, 1e18);
  graph.resize(num_nodes);
  pred.resize(num_nodes, 0);
  for (int i = 0; i < num_edges; i++) {
    input_file >> node1 >> node2 >> weight;
    graph[node1 - 1].push_back({node2 - 1, weight});
    graph[node2 - 1].push_back({node1 - 1, weight});
  }
  input_file.close();
  start--;
  end--;
  dxra(start, num_nodes);
  if (dist[end] == 1e18) {
    output_file << -1;
  } else {
    vector<int> path;
    output_file << dist[end] << endl;
    path.push_back(end + 1);
    while (end != start) {
      path.push_back(pred[end] + 1);
      end = pred[end];
    }
    output_file << path.size() << endl;
    for (int i = path.size() - 1; i >= 0; i--) {
      output_file << path[i] << " ";
    }
  }
  output_file.close();
  return 0;
}
