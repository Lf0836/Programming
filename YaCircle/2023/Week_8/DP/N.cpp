#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string calculateOperations(int n) {
  vector<int> dp(n + 1, INT_MAX);
  dp[1] = 0;

  for (int i = 2; i <= n; i++) {
    if (i % 3 == 0) {
      dp[i] = min(dp[i], dp[i / 3] + 1);
    }
    if (i % 2 == 0) {
      dp[i] = min(dp[i], dp[i / 2] + 1);
    }
    dp[i] = min(dp[i], dp[i - 1] + 1);
  }

  string sequence;
  while (n > 1) {
    sequence += to_string(n) + " ";
    if (dp[n] == dp[n - 1] + 1) {
      n -= 1;
    } else if (n % 3 == 0 && dp[n] == dp[n / 3] + 1) {
      n /= 3;
    } else {
      n /= 2;
    }
  }
  sequence += "1";

  reverse(sequence.begin(), sequence.end());

  return sequence;
}

int main() {
  int n;
  cin >> n;

  string result = calculateOperations(n);
  cout << result << endl;

  return 0;
}