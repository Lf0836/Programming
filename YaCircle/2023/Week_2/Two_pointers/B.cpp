#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n1, n2, n3, n4;
  cin >> n1;
  vector<int> a1(n1);
  for (int i = 0; i < n1; i++) {
    cin >> a1[i];
  }
  cin >> n2;
  vector<int> a2(n2);
  for (int i = 0; i < n2; i++) {
    cin >> a2[i];
  }
  cin >> n3;
  vector<int> a3(n3);
  for (int i = 0; i < n3; i++) {
    cin >> a3[i];
  }
  cin >> n4;
  vector<int> a4(n4);
  for (int i = 0; i < n4; i++) {
    cin >> a4[i];
  }
  sort(a1.begin(), a1.end());
  sort(a2.begin(), a2.end());
  sort(a3.begin(), a3.end());
  sort(a4.begin(), a4.end());

  int i1 = 0, i2 = 0, i3 = 0, i4 = 0;
  int minimum = min({a1[0], a2[0], a3[0], a4[0]});
  int maximum = max({a1[0], a2[0], a3[0], a4[0]});
  int diff = maximum - minimum;
  int min1 = i1;
  int min2 = i2;
  int min3 = i3;
  int min4 = i4;

  while (i1 < n1 && i2 < n2 && i3 < n3 && i4 < n4) {
    minimum = min({a1[i1], a2[i2], a3[i3], a4[i4]});
    maximum = max({a1[i1], a2[i2], a3[i3], a4[i4]});
    int diff_now = maximum - minimum;
    if (diff_now < diff) {
      diff = diff_now;
      min1 = i1;
      min2 = i2;
      min3 = i3;
      min4 = i4;
    }
    if (diff_now == 0) {
      break;
    }

    while (i1 < (int)a1.size() && minimum == a1[i1]) {
      i1++;
    }
    while (i2 < (int)a2.size() && minimum == a2[i2]) {
      i2++;
    }
    while (i3 < (int)a3.size() && minimum == a3[i3]) {
      i3++;
    }
    while (i4 < (int)a4.size() && minimum == a4[i4]) {
      i4++;
    }
  }

  cout << a1[min1] << " " << a2[min2] << " " << a3[min3] << " " << a4[min4]
       << endl;

  return 0;
}