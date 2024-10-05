#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
    vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));
  for (int j = 1; j < 10; j++) {
    dp[1][j] = 1;
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = j - 1; k <= j + 1; k++) {
        if (k >= 0 && k <= 9) {
          dp[i][j] += dp[i - 1][k];
        }
      }
    }
  }
  long long res = 0;
  for (int j = 0; j < 10; j++) {
    res += dp[n][j];
  }
  cout << res << endl;
  return 0;
}
