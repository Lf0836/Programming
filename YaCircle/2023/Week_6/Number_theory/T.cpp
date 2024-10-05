#include <iostream>
#include <vector>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int count = 0;
  vector<bool> isItPrime(b + 3, true);
  isItPrime[0] = false;
  isItPrime[1] = false;
  for (int i = 2; i * i <= b + 2; i++) {
    if (isItPrime[i]) {
      for (int j = i * i; j <= b + 2; j += i) {
        isItPrime[j] = false;
      }}}
  for (int i = a; i <= b; i++) {
    if (isItPrime[i]) {
      if (isItPrime[i + 2] || isItPrime[i - 2]) {
        count++;
        }}}
  cout << count << endl;
  return 0;
}
