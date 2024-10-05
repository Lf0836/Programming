#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main() {
  int n;
  cin >> n;
  vector<int> a(5001, 0);
  vector<int> b(5001, 0);
  vector<int> c(5001, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
    vector<int> dp(n + 1, 0);
  dp[0] = 0;
  dp[1] = a[1];
  if (n > 1) {
    dp[2] = min(a[1] + a[2], b[1]);
  }
  for (int i = 3; i <= n; i++) {
    dp[i] =
        min(dp[i - 1] + a[i], min(dp[i - 2] + b[i - 1], dp[i - 3] + c[i - 2]));
  }
  cout << dp[n] << endl;
  return 0;
}
