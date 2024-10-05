#include <iostream>

using namespace std;

int func(int n, int m) {
  while (m != 0) {
    n %= m;
    swap(n, m);
  }
  return n;
}

int main() {
  int n, m;
  cin >> n >> m;
  cout << func(n, m);
  return 0;
}
