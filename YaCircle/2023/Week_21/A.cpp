#include <iostream>
#include <vector>

using namespace std;

int upper(vector<int>& arr, int index) {
  while (index) {
    if (arr[index / 2 - 1 + index % 2] < arr[index]) {
      swap(arr[index / 2 - 1 + index % 2], arr[index]);
      index = index / 2 - 1 + index % 2;
    } else {
      return index;
    }
  }
  return 0;
}

int main() {
  int n, m, add, k;
  cin >> n;
  vector<int> arr(n);
  for (int j = 0; j < n; ++j) {
    cin >> arr[j];
  }
  cin >> m;
  vector<int> arrey(m);
  int z = m;
  for (; m > 0; --m) {
    cin >> k;
    cin >> add;
    arr[k - 1] = arr[k - 1] + add;
    arrey[z - m] = upper(arr, k - 1);
  }
  for (int i = 0; i < z; ++i) {
    cout << arrey[i] + 1 << endl;
  }
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << ' ';
  }
  return 0;
}
