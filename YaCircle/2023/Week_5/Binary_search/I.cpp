#include <iostream>

using namespace std;

int main() {
  long long m, n, k;
  cin >> m >> k >> n;
  long long l = 1;
  long long r = max(m, k) * n;
  while (l < r) {
    long long mid = l + (r - l) / 2;
    if ((mid / m) * (mid / k) >= n) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l;
}
