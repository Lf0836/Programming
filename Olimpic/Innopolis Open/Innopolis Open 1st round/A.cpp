#include <iostream>

using namespace std;

int main() {
  long long a, b;
  cin >> a >> b;
  long long x, y;
  cin >> x >> y;
  if (a * x > b * y) {
    cout << (b * y - a * x) / (2 * x) << endl;
  }
  if (a * x < b * y) {
    cout << (b * y - a * x) / (2 * y) << endl;
  }
  if (a * x == b * y) {
    cout << a << endl;
  }
}
