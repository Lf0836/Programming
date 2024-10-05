#include <iostream>
#include <vector>

using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  x--;
  y--;
  vector<vector<int>> positions(8, vector<int>(8));
  for (int i = 1; i < 8; i += 2) {
    positions[7][i] = 1;
  }
  for (int i = 6; i >= y; i--) {
    for (int j = i % 2; j < 8; j += 2) {
      if (j == 0) {
        positions[i][j] = positions[i + 1][j + 1];
      } else if (j == 7) {
        positions[i][j] = positions[i + 1][j - 1];
      } else {
        positions[i][j] = positions[i + 1][j - 1] + positions[i + 1][j + 1];
      }
    }
  }
  cout << positions[y][x] << endl;
  return 0;
}
