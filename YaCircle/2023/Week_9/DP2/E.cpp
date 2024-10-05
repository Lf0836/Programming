#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> search_of_min_notes(const vector<int>& notes, int s) {
  vector<int> dp(s + 1, -1);
  dp[0] = 0;
  vector<vector<int>> selet_notes(s + 1);
  for (int i = 1; i <= s; i++) {
    for (int j = 0; j < notes.size(); j++) {
      if (i >= notes[j] && dp[i - notes[j]] != -1) {
        if (dp[i] == -1 || dp[i - notes[j]] + 1 < dp[i]) {
          dp[i] = dp[i - notes[j]] + 1;
          selet_notes[i] = selet_notes[i - notes[j]];
          selet_notes[i].push_back(notes[j]);
        }
      }
    }
  }
  return selet_notes[s];
}

int main() {
  int n;
  cin >> n;
  vector<int> notes(n);
  for (int i = 0; i < n; i++) {
    cin >> notes[i];
  }
  int s;
  cin >> s;
  vector<int> dp(s + 1, -1);
  dp[0] = 0;
  vector<vector<int>> selet_notes(s + 1);
  for (int i = 1; i <= s; i++) {
    for (int j = 0; j < notes.size(); j++) {
      if (i >= notes[j] && dp[i - notes[j]] != -1) {
        if (dp[i] == -1 || dp[i - notes[j]] + 1 < dp[i]) {
          dp[i] = dp[i - notes[j]] + 1;
          selet_notes[i] = selet_notes[i - notes[j]];
          selet_notes[i].push_back(notes[j]);
        }
      }
    }
  }
  if (selet_notes[s].empty()) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < selet_notes[s].size(); i++) {
      cout << selet_notes[s][i] << " ";
    }
  }
  return 0;
}
