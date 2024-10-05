#include <iostream>

using namespace std;

bool func(int n) {
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
  // Гипотеза Гольдбаха
  int n;
  cin >> n;
  int per1 = 0;
  int per2 = 0;
  for (int i = 2; i + i <= n; i++) {
    if (func(i)) {
      per1 = i;
      if (func(n - i)) {
        per2 = n - i;
        cout << per1 << " " << per2;
        return 0;
      }
    }
  }
}
