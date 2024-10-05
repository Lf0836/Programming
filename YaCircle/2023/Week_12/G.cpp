#include <iostream>

using namespace std;

int calcLeng(int k) {
  if (k == -1) {
    return 0;
  }
  int x = calcLeng(k - 1);
  return x + k + 3 + x;
}
char solPuzz(int n, int k) {
  if (n > calcLeng(k)) {
    return solPuzz(n, k + 1);
  }
  if (n <= calcLeng(k - 1)) {
    return solPuzz(n, k - 1);
    }
  n = n - calcLeng(k - 1);
  if (n <= k + 3) {
    return (n == 1) ? 'm' : 'o';
  }
  n = n - (k + 3);
  return solPuzz(n, k - 1);
}
int main() {
  int n;
  cin >> n;
  cout << solPuzz(n, 0) << endl;
  return 0;
}
