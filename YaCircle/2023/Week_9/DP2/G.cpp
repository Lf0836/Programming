#include <iostream>
#include <vector>

using namespace std;

bool search_patron(const vector<int>& m, int n) {
  int sum = 0;
  for (int num : m) {
    sum += num;
  }
  if (sum % 2 != 0) {
    return false;
  }
  int target = sum / 2;
  vector<vector<bool>> table(target + 1, vector<bool>(n + 1, false));
  for (int i = 0; i <= n; i++) {
    table[0][i] = true;
  }
  for (int i = 1; i <= target; i++) {
    table[i][0] = false;
  }
  for (int i = 1; i <= target; i++) {
    for (int j = 1; j <= n; j++) {
      table[i][j] = table[i][j - 1];
      if (i >= m[j - 1]) {
        table[i][j] = table[i][j] || table[i - m[j - 1]][j - 1];
      }
    }
  }
  return table[target][n];
}

int main() {
  int n;
  cin >> n;
  vector<int> m(n);
  for (int i = 0; i < n; i++) {
    cin >> m[i];
  }
  if (search_patron(m, n)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
