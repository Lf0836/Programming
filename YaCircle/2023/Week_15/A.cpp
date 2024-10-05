#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool checkOrder(int n, int m) {
  vector<vector<int>> graph(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
  }
  vector<int> position(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    int v;
    cin >> v;
    position[v] = i;
  }
  for (int i = 1; i <= n; i++) {
    for (int j : graph[i]) {
      if (position[i] > position[j]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;
  if (checkOrder(n, m)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
