#include <iostream>
#include <vector>

using namespace std;

bool canPlaceQueen(vector<int>& board, int row, int col) {
  for (int i = 0; i < row; i++) {
    if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
      return false;
    }
  }
  return true;
}

void countQueenPlacements(vector<int>& board, int row, int n, int& count) {
  if (row == n) {
    count++;
    return;
  }
  for (int col = 0; col < n; col++) {
    if (canPlaceQueen(board, row, col)) {
      board[row] = col;
      countQueenPlacements(board, row + 1, n, count);
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> board(n, 0);
  int count = 0;
  countQueenPlacements(board, 0, n, count);
  cout << count << endl;
  return 0;
}
