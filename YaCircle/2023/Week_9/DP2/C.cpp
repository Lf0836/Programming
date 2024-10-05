#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> sqa(n);
  for (int i = 0; i < n; i++) {
    cin >> sqa[i];
  }
  int m;
  cin >> m;
  vector<int> sqb(m);
  for (int i = 0; i < m; i++) {
    cin >> sqb[i];
  }
  int sqas = sqa.size();
  int sqbs = sqb.size();
  vector<int> dp(sqbs + 1), dpp(sqbs + 1);
  for (int i = 0; i <= sqas; i++) {
    for (int j = 0; j <= sqbs; j++) {
      if (i == 0 || j == 0) {
        dp[j] = 0;
      } else {
        if (sqa[i - 1] == sqb[j - 1]) {
          dp[j] = dpp[j - 1] + 1;
        } else {
          dp[j] = max(dpp[j], dp[j - 1]);
        }
      }
    }
    dpp = dp;
  }
  cout << dp[sqbs] << endl;
  return 0;
}
