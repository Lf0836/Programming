#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int l = 1;
  int r = 1e9;
  while (l < r) {
    int m = (l + r) / 2;
    int count = 0;
    for (int i = 0; i < n; i++) {
      count += arr[i] / m;
    }
    if (count >= k) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  cout << l - 1;
  return 0;
}
