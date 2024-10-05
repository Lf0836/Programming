#include <iostream>
#include <vector>

using namespace std;

int parig(int i, int j, int row, int col, vector<vector<int>>& gr) {
  if (i >= 0 && j >= 0 && i < row && j < col) {
    if (gr[i][j] == -1) {
      gr[i][j] = parig(i - 2, j - 1, row, col, gr) +
                 parig(i - 2, j + 1, row, col, gr) +
                 parig(i - 1, j - 2, row, col, gr) +
                 parig(i + 1, j - 2, row, col, gr);
    }
  } else {
    return 0;
  }
  return gr[i][j];
}

int main() {
  int row, col;
  cin >> row >> col;
  vector<vector<int>> gr(row, vector<int>(col, -1));
  gr[0][0] = 1;
  cout << parig(row - 1, col - 1, row, col, gr) << endl;
  return 0;
}
