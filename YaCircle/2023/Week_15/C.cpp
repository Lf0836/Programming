#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<vector<int>> g, gr;
vector<int> us, top, col;
set<pair<int, int>> s;

void dfs1(int v) {
  us[v] = 1;
  for (int to : g[v]) {
    if (!us[to]) {
      dfs1(to);
    }
  }
  top.push_back(v);
}

void dfs(int v, int c) {
  col[v] = c;
  for (int to : gr[v]) {
    if (col[to] == -1) {
      dfs(to, c);
    }
  }
}

int main() {
  int n, m, a, b;
  cin >> n >> m;
  g.resize(n + 1);
  gr.resize(n + 1);
  us.resize(n + 1);
  col.assign(n + 1, -1);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    g[a].push_back(b);
    gr[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    if (!us[i]) dfs1(i);
  }
  int c = 0;
  for (int i = 1; i <= n; i++) {
    int v = top[n - i];
    if (col[v] == -1) dfs(v, c++);
  }
  for (int i = 1; i < g.size(); i++) {
    for (int to : g[i]) {
      if (col[i] != col[to]) {
        s.insert(make_pair(col[i], col[to]));
      }
    }
  }
  cout << s.size() << endl;
  return 0;
}
