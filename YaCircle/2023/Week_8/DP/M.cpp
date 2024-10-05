#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<long long>> dp(10, vector<long long>(n + 1));
  for (int i = 0; i < 10; i++) {
    dp[i][1] = 1;
  }
  for (int j = 2; j <= n; j++) {
    for (int i = 0; i < 10; i++) {
      switch (i) {
        case 0:
          dp[0][j] = (dp[4][j - 1] + dp[6][j - 1]) % 1000000000;
          break;
        case 1:
          dp[1][j] = (dp[6][j - 1] + dp[8][j - 1]) % 1000000000;
          break;
        case 2:
          dp[2][j] = (dp[9][j - 1] + dp[7][j - 1]) % 1000000000;
          break;
        case 3:
          dp[3][j] = (dp[8][j - 1] + dp[4][j - 1]) % 1000000000;
          break;
        case 4:
          dp[4][j] = (dp[0][j - 1] + dp[3][j - 1] + dp[9][j - 1]) % 1000000000;
          break;
        case 6:
          dp[6][j] = (dp[0][j - 1] + dp[1][j - 1] + dp[7][j - 1]) % 1000000000;
          break;
        case 7:
          dp[7][j] = (dp[6][j - 1] + dp[2][j - 1]) % 1000000000;
          break;
        case 8:
          dp[8][j] = (dp[1][j - 1] + dp[3][j - 1]) % 1000000000;
          break;
        case 9:
          dp[9][j] = (dp[2][j - 1] + dp[4][j - 1]) % 1000000000;
          break;
      }
    }
  }
  long long sum = 0;
  for (int i = 1; i < 10; i++) {
    if (i != 8) {
      sum = (sum + dp[i][n]) % 1000000000;
    }
  }
  cout << sum;
  return 0;
}
