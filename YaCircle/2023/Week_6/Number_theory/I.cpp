#include <iostream>
#include <vector>

using namespace std;

int nod(int a, int b) {
  if (b == 0) {
    return a;
  }
  return nod(b, a % b);
}

int findNOD(vector<int> arr, int n) {
  int res = arr[0];
  for (int i = 1; i < n; i++) {
    res = nod(arr[i], res);
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << findNOD(arr, n);
}
