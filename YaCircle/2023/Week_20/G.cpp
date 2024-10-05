#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  vector<vector<int>> dp(N, vector<int>(N, 0));
  for (int len = 2; len <= N; ++len) {
    for (int i = 0; i <= N - len; ++i) {
      int j = i + len - 1;
      dp[i][j] = dp[i + 1][j - 1] + (S[i] != S[j]);
    }
  }
  int almost_palindromes = 0;
  for (int len = 1; len <= N; ++len) {
    for (int i = 0; i <= N - len; ++i) {
      int j = i + len - 1;
      if (dp[i][j] <= K) {
        almost_palindromes++;
      }
    }
  }
  cout << almost_palindromes << endl;
  return 0;
}
