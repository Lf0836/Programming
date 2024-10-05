#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int l, ct;
  cin >> l >> ct;
  vector<vector<int>> set(l, vector<int>(ct));
  vector<char> road;
  for (int i = 0; i < l; ++i) {
    for (int j = 0; j < ct; ++j) {
      cin >> set[i][j];
    }
  }
  int Up, Left;
  for (int i = 0; i < l; ++i) {
    for (int j = 0; j < ct; ++j) {
      Up = (i > 0) ? set[i - 1][j] : 0;
      Left = (j > 0) ? set[i][j - 1] : 0;
      set[i][j] += max(Up, Left);
    }
  }
  int i = l - 1, j = ct - 1;
  while (i > 0 || j > 0) {
    if (j > 0 && i > 0) {
      if (set[i][j - 1] > set[i - 1][j]) {
        road.push_back('R');
        --j;
      } else {
        road.push_back('D');
        --i;
      }
    } else if (j > 0) {
      road.push_back('R');
      --j;
    } else {
      road.push_back('D');
      --i;
    }
  }
  cout << set[l - 1][ct - 1] << endl;
  reverse(road.begin(), road.end());
  for (char ch : road) {
    cout << ch << ' ';
  }
  return 0;
}
