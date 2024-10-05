#include <iostream>
#include <string>

using namespace std;

int main() {
  long n, a, b, c;
  cin >> n >> a >> b >> c;
  long long result = (n / (a * b)) * (c + a) + (n % (a*b)) / b + 1;
  cout << result;
  return 0;
}
