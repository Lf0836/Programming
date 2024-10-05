#include <iostream>
#include <vector>

using namespace std;

vector<int> primes(int n) {
  vector<int> p(n + 1, 0);
  vector<int> primes;  // вектор найденных простых чисел
  for (int i = 2; i <= n; ++i) {
    if (p[i] == 0) {  // i - простое
      p[i] = i;
      primes.push_back(i);
    }
    for (int x : primes) {
      if (x > p[i] || 1ll * x * i > n) break;
      p[x * i] = x;
    }
  }
  return p;
}

int main() {
  int m, n;
  cin >> m >> n;
  vector<int> p = primes(n);
  bool isPrime = false;
  for (int i = m; i <= n; ++i) {
    if (p[i] == i) {
      cout << i << endl;
      isPrime = true;
    }
  }
  if (!isPrime) {
    cout << -1 << endl;
  }
  return 0;
}
