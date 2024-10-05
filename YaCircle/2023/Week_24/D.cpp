#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
  long long xPoint;
  long long yPoint;
};

int main() {
  int n;
  cin >> n;
  vector<Point> vec(n);
  for (int i = 0; i < n; ++i) {
    cin >> vec[i].xPoint >> vec[i].yPoint;
  }
  long long number = 0;
  for (int i = 0; i < n; ++i) {
    int j = (i + 1) % n;
    number += vec[i].xPoint * vec[j].yPoint;
    number -= vec[i].yPoint * vec[j].xPoint;
  }
  double ans = abs(number) / 2.0;
  cout << ans << endl;
  return 0;
}
