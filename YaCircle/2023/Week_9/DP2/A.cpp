#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, w;
  cin >> n >> w;
  vector<int> g(n);
  for (int i = 0; i < n; i++) {
    cin >> g[i];
  }
  vector<vector<bool>> dp(n + 1, vector<bool>(w + 1, false));
  dp[0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= w; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j >= g[i - 1]) {
        dp[i][j] = dp[i][j] || dp[i - 1][j - g[i - 1]];
      }
    }
  }
  if (dp[n][w]) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
  return 0;
}
