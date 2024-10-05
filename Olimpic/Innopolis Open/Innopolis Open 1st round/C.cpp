#include <iostream>
#include <vector>

using namespace std;

int main() {
  int l, k;
  cin >> l >> k;
  vector<int> arr(l);
  for (int i = 0; i < l; i++) {
    cin >> arr[i];
  }
  int count = 0;
  for (int i = 0; i < l / 2 + 1; i++) {
    if (arr[i] < arr[l - i - 1]) {
      if (arr[l - i - 1] - arr[i] > k) {
        arr[i] += k;
        count++;
      } else {
        arr[i] += arr[i] - arr[l - i - 1];
        count++;
      }
    }
    if (arr[i] > arr[l - i - 1]) {
      if (arr[i] - arr[l - i - 1] > k) {
        arr[l - i - 1] += k;
        count++;
      } else {
        arr[l - i - 1] += arr[l - i - 1] - arr[i];
        count++;
      }
    }
    i++;
  }
  cout << count << endl;
  for (int i = 0; i < l; i++){
    cout << arr[i] << " ";
  }
}
