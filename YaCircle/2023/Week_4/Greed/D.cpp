#include <iostream>

using namespace std;

int main() {
  int m, n;
  cin >> m >> n;
  while (n > 0 || m > 0) {
    if (n != 0) {
      cout << 'G';
      n--;
    }
    if (n != 0) {
      cout << 'G';
      n--;
    }
    if (m != 0) {
      cout << 'B';
      m--;
    }
  }
}
