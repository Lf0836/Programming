#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> combinations;

void splitSummands(int n, vector<int>& summands, int start = 1) {
  if (n == 0) {
    combinations.push_back(summands);
    return;
  }
  for (int i = start; i <= n; i++) {
    summands.push_back(i);
    splitSummands(n - i, summands, i);
    summands.pop_back();
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> summands;
  splitSummands(n, summands);
  for (int i = combinations.size() - 1; i >= 0; i--) {
    for (int j = 0; j < combinations[i].size(); j++) {
      if (j > 0) {
        cout << " ";
      }
      cout << combinations[i][j];
    }
    cout << endl;
  }
  return 0;
}
