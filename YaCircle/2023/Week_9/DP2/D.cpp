#include <iostream>
#include <string>
#include <vector>

using namespace std;

int counter(const string& str, int n, int k) {
  vector<vector<int>> dp(n, vector<int>(n, 0));
  for (int leng = 1; leng < n; leng++) {
    for (int l = 0; l < n - leng; l++) {
      int r = l + leng;

      if (leng == 1) {
        if (str[l] != str[r]) {
          dp[l][r] = 1;
        } else {
          dp[l][r] = 0;
        }
      } else {
        dp[l][r] = dp[l + 1][r - 1] + (str[l] != str[r]);
      }
    }
  }

  int count = 0;
  for (int leng = 0; leng < n; leng++) {
    for (int l = 0; l < n - leng; l++) {
      int r = l + leng;

      if (dp[l][r] <= k) {
        count++;
      }
    }
  }

  return count;
}

int main() {
  int n, k;
  cin >> n >> k;
  string str;
  cin >> str;
  int count = counter(str, n, k);
  cout << count << endl;
  return 0;
}
