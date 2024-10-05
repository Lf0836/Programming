#include <iostream>
#include <vector>

using namespace std;

int countPaintedCells(vector<vector<char>>& grid) {
  int n = grid.size();
  int m = grid[0].size();
  int count = 0;

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      int paintedCount = 0;

      if (grid[i][j] == '#') paintedCount++;
      if (grid[i][j + 1] == '#') paintedCount++;
      if (grid[i + 1][j] == '#') paintedCount++;
      if (grid[i + 1][j + 1] == '#') paintedCount++;

      if (paintedCount >= 3) {
        count += 4 - paintedCount;
      }
    }
  }

  return count;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<char>> grid(n, vector<char>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }

  int result = countPaintedCells(grid);
  cout << result << endl;

  return 0;
}
