#include <iostream>

using namespace std;

int const MAX = 101;
int const INF = 10000000;

int g[MAX][MAX];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> g[i][j];
      if (g[i][j] < 0) g[i][j] = INF;
    }
  int res = 0;
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (g[i][k] + g[k][j] < g[i][j]) g[i][j] = g[i][k] + g[k][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if ((g[i][j] > res) && (g[i][j] < INF)) res = g[i][j];
  cout << res << endl;
  return 0;
}
