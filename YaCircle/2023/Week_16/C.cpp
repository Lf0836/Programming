#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<long long> dist;
vector<long long> NodPric;

void dstra(int SN) {
  dist[SN] = 0;
  set<pair<int, int>> q;
  q.insert({0, SN});
  while (!q.empty()) {
    int curN = q.begin()->second;
    q.erase(q.begin());
    for (auto edge : graph[curN]) {
      if (dist[edge.first] > dist[curN] + edge.second) {
        q.erase({dist[edge.first], edge.first});
        dist[edge.first] = dist[curN] + edge.second;
        q.insert({dist[edge.first], edge.first});
      }
    }
  }
}

int main() {
  int NN, NE, NO, NT, W;
  cin >> NN;
  NodPric.resize(NN);
  for (int i = 0; i < NN; i++) {
    cin >> NodPric[i];
  }
  for (int i = 0; i < NE; i++) {
    cin >> NO >> NT;
    graph[NO - 1].push_back({NO - 1 + NN, NodPric[NO - 1]});
    graph[NO - 1 + NN].push_back({NT - 1, 0});
    graph[NO - 1 + NN].push_back({NT - 1 + NN, NodPric[NO - 1]});
    graph[NT - 1].push_back({NT - 1 + NN, NodPric[NT - 1]});
    graph[NT - 1 + NN].push_back({NO - 1, 0});
    graph[NT - 1 + NN].push_back({NO - 1 + NN, NodPric[NT - 1]});
  }
  dstra(0);
  if (dist[NN - 1] == 1e18) {
    cout << -1;
  } else {
    cout << min(dist[NN - 1], dist[2 * NN - 1]) << endl;
  }
  return 0;
}
