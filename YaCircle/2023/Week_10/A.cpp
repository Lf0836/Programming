#include <iostream>
#include <vector>
using namespace std;

long long c(int n, int k) {
  vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 1;
    dp[i][i] = 1;
    for (int j = 1; j < i; j++) {
      dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
    }
  }
    return dp[n][k];
}

int main() {
    int n;
    cin >> n;
    cout << c(n, 5) + c(n, 6) + c(n, 7) << endl;
    return 0;
}
