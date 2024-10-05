#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int rows, columns;
  cin >> rows >> columns;
  vector<vector<int>> grid(rows, vector<int>(columns));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      cin >> grid[i][j];
    }
  }
  int maxSideLength = 0, maxRowIndex = 0, maxColumnIndex = 0;
  vector<vector<int>> dp(rows, vector<int>(columns));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = grid[i][j];
      } else if (grid[i][j] == 1) {
        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
      }
      if (dp[i][j] >= maxSideLength) {
        maxSideLength = dp[i][j];
        maxRowIndex = i - maxSideLength + 1;
        maxColumnIndex = j - maxSideLength + 1;
      }
    }
  }
  cout << maxSideLength << endl;
  cout << maxRowIndex + 1 << " " << maxColumnIndex + 1 << endl;
  return 0;
}
