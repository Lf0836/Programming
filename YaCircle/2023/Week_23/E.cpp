#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

struct Point {
  double x;
  double y;
};

int main() {
  Point p;
  double a, b, c;
  cin >> p.x >> p.y >> a >> b >> c;
  cout << fixed << setprecision(6) << abs(a * p.x + b * p.y + c) / sqrt(a * a + b * b) << endl;
  return 0;
}
