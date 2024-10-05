#include <iostream>

using namespace std;

int counting(int prev, int n) {
  if (0 == n) return 1;
  int res = 0;
  for (int lvl = 1; lvl < prev; ++lvl) {
    if ((n - lvl) < 0) break;
    res += counting(lvl, n - lvl);
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  cout << counting(n + 1, n);
}
