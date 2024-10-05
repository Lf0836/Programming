#include <iostream>
#include <cmath>

#define E 1e-5

using namespace std;

double leng(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool is_in(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4,
                double x, double y) {
  return (abs(leng(x1, y1, x, y) - leng(x1, y1, x2, y2) +
              leng(x, y, x2, y2)) <= E &&
          abs(leng(x3, y3, x, y) - leng(x3, y3, x4, y4) +
              leng(x, y, x4, y4)) <= E);
}

bool is_overlap(int x1, int y1, int x2, int y2, int x3, int y3, int x4,
                int y4) {
  return (abs(leng(x1, y1, x3, y3) - leng(x1, y1, x2, y2) +
              leng(x3, y3, x2, y2)) <= E ||
          abs(leng(x1, y1, x4, y4) - leng(x1, y1, x2, y2) +
              leng(x4, y4, x2, y2)) <= E ||
          abs(leng(x3, y3, x1, y1) - leng(x3, y3, x4, y4) +
              leng(x1, y1, x4, y4)) <= E ||
          abs(leng(x3, y3, x2, y2) - leng(x3, y3, x4, y4) +
              leng(x2, y2, x4, y4)) <= E);
}

int main() {
  long x1, y1, x2, y2, x3, y3, x4, y4;
  double x, y;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  long long ky1, kx1, b1, ky2, kx2, b2;
  ky1 = y2 - y1;
  ky2 = y4 - y3;
  kx1 = x2 - x1;
  kx2 = x4 - x3;
  b1 = x1 * y2 - x2 * y1;
  b2 = x3 * y4 - x4 * y3;
  if (kx1 * ky2 == kx2 * ky1) {
    if (b1 * ky2 != b2 * ky1 && b1 * kx2 != b2 * kx1)
      cout << "No";
    else if (is_overlap(x1, y1, x2, y2, x3, y3, x4, y4))
      cout << "Yes";
    else
      cout << "No";
  } else {
    y = (double)(b2 * ky1 - b1 * ky2) / (double)(kx1 * ky2 - kx2 * ky1);
    x = (double)(b1 * kx2 - b2 * kx1) / (double)(ky1 * kx2 - ky2 * kx1);
    if (is_in(x1, y1, x2, y2, x3, y3, x4, y4, x, y))
      cout << "Yes";
    else
      cout << "No";
  }
  return 0;
}
