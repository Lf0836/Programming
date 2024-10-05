#include <iostream>
#include <vector>

using namespace std;

void hpfy(vector<int>& arr, int n, int i) {
  int max_itm = i;
  int r = 2 * i + 2;
  int l = 2 * i + 1;
  if (r < n && arr[r] > arr[max_itm]) {
    max_itm = r;
  }
  if (l < n && arr[l] > arr[max_itm]) {
    max_itm = l;
  }
  if (max_itm != i) {
    swap(arr[i], arr[max_itm]);
    hpfy(arr, n, max_itm);
  }
}

void hpst(vector<int>& arr) {
  int n = arr.size();
  for (int i = n / 2 - 1; i >= 0; i--) {
    hpfy(arr, n, i);
  }
  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);
    hpfy(arr, i, 0);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  hpst(arr);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }
  return 0;
}
