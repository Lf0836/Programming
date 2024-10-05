#include <iostream>
#include <vector>

using namespace std;

int main() {
  int r, col;
  cin >> r >> col;
  vector<vector<int>> dp(r, vector<int>(col, 0));
  dp[0][0] = 1;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < col; j++) {
      if (i >= 2 && j >= 2) {
        dp[i][j] += dp[i - 1][j - 2] + dp[i - 2][j - 1];
      } else if (i >= 1 && j >= 2) {
        dp[i][j] += dp[i - 1][j - 2];
      } else if (i >= 2 && j >= 1) {
        dp[i][j] += dp[i - 2][j - 1];
      }
    }
  }
  cout << dp[r - 1][col - 1] << endl;
  return 0;
}
