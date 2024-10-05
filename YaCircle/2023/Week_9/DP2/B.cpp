#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<int> d(100001, 0);
  d[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = m; j >= 0; j--) {
      if (d[j] == 1) {
        d[j + arr[i]] = 1;
      }
    }
  }
  for (int i = m; i >= 0; i--) {
    if (d[i] == 1 && i <= m) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
