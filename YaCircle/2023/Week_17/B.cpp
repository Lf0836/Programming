#include <bitset>
#include <iostream>

using namespace std;

int length(int k) {
  long l = 1;
  for (; k /= 10; ++l);
  return l;
}

int main() {
  long A, n, res = 0;
  cin >> A >> n;
  long leng = length(A);
  bitset<8> binNum(A);
  for (long i = 0; i < n; i++) {
    res += binNum[leng - i];
  }
  cout << res;
  return 0;
}
