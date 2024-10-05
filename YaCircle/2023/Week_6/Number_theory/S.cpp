#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> dec(int n) {
  vector<int> ans(0);
  int d = 2;
  while (d * d <= n) {
    if (n % d == 0) {
      ans.push_back(d);
      n /= d;
    } else {
      d += 1;
    }
  }
  if (n > 1) ans.push_back(n);
  return ans;
}

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1;
  } else {
    vector<int> tmp = dec(n);
    unordered_set<int> s;
    for (int el : tmp) s.insert(el);
    vector<int> a(0);
    for (int el : s) a.push_back(el);
    int y = 1;
    for (int i = 0; i < a.size(); i++) y *= a[i];
    if (y >= 29) {
      cout << y;
    } else {
      int k = 1;
      int n = k * y;
      while ((int)pow(n, n) % n != 0) {
        n = k * y;
        k += 1;
      }
      cout << n;
    }
  }
}
