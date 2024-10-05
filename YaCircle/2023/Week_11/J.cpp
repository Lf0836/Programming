#include <iostream>
#include <vector>

using namespace std;

int countBrackets(int n) {
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 1;
    dp[i][1] = 2;
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 0; i <= n - len; i++) {
      int j = i + len - 1;
      dp[i][j] = dp[i + 1][j - 1] + dp[i][j - 1] * 2;
    }
  }
  return dp[0][n - 1];
}

int main() {
  int n;
  cin >> n;
  cout << countBrackets(n) << endl;
  return 0;
}
