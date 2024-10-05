#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  int maximum = 1;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      if (n / i > maximum) {
        maximum = n / i;
      }
    }
  }
  cout << maximum << ' ' << n - maximum << endl;
  return 0;
}
