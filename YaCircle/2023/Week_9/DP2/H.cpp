#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<bool> dp(n + 1);
    dp[1] = true;
    int TFl = 0;
    for (int i = 1; i <= n; i++) {
      if (a <= i) {
        dp[i] = dp[i] || dp[i-a];
      }
      if (b <= i) {
        dp[i] = dp[i] || dp[i-b];
      }
      if (c <= i) {
        dp[i] = dp[i] || dp[i-c];
      }
      TFl += int(dp[i]);
    }
    cout << TFl << endl;
    return 0;
}
