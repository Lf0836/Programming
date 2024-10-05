#include <cmath>
#include <iostream>
#include <vector>

bool has_odd_divisor(long long n) {
  if (n % 2 == 1) {
    return true;
  }
  while (n % 2 == 0) {
    n /= 2;
  }
  return n > 1;
}

int main() {
  int t;
  std::cin >> t;
  std::vector<long long> deadlines(t);
  for (int i = 0; i < t; ++i) {
    std::cin >> deadlines[i];
  }
  for (int i = 0; i < t; ++i) {
    if (has_odd_divisor(deadlines[i])) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }
  return 0;
}
