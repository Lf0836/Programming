#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, r;
  cin >> n >> r;

  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  long long result = 0;
  int left = 0, right = 1;
  while (left < n - 1 && right < n) {
    if (arr[right] - arr[left] > r) {
      result += n - right;
      left++;
    } else {
      right++;
    }
  }
  cout << result << endl;
}