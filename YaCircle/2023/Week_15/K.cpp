#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int Nmax = 101;

int pole[Nmax][Nmax];
int paint[Nmax][Nmax];
int s[Nmax * Nmax];
int n, m, res, num;

void go(int x, int y) {
  if (paint[x][y] != 0) return;
  paint[x][y] = num;
  if (x >= 1 && y - 1 >= 1) {
    if (pole[x][y - 1] == pole[x][y]) go(x, y - 1);
    if (pole[x][y - 1] < pole[x][y]) s[num] = 1;
  }
  if (x >= 1 && y + 1 <= m) {
    if (pole[x][y + 1] == pole[x][y]) go(x, y + 1);
    if (pole[x][y + 1] < pole[x][y]) s[num] = 1;
  }
  if (x + 1 <= n && y >= 1) {
    if (pole[x + 1][y] == pole[x][y]) go(x + 1, y);
    if (pole[x + 1][y] < pole[x][y]) s[num] = 1;
  }
  if (x - 1 >= 1 && y >= 1) {
    if (pole[x - 1][y] == pole[x][y]) go(x - 1, y);
    if (pole[x - 1][y] < pole[x][y]) s[num] = 1;
  }
}

void SolveMachine() {
  memset(paint, 0, sizeof(paint));
  memset(s, 0, sizeof(s));
  res = 0;
  num = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (paint[i][j] == 0) {
        num++;
        go(i, j);
      }
    }
  }

  for (int i = 1; i <= num; ++i) {
    if (s[i] == 0) res++;
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> pole[i][j];
    }
  }
  SolveMachine();
  cout << res << endl;
  return 0;
}
