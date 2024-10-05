#include <iostream>

using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;
  long long result = n * k;
  while (k > 0) {
    long long k2 = k;
    k = n % k;
    n = k2;
  }
  result /= n;
  cout << result << endl;
  return 0;
}
