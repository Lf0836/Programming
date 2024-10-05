#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool canPrint(const vector& arr) {
  int n = arr.size();
  vector prefixSum(2 * n + 1, 0);

  for (int i = 0; i < n; i++) {
    prefixSum[i + 1] = prefixSum[i] + arr[i];
    prefixSum[i + n + 1] = prefixSum[i + n] + arr[i];
  }

  for (int l1 = 0; l1 < n; l1++) {
    for (int r1 = l1; r1 < n; r1++) {
      long long sum1 = prefixSum[r1 + 1] - prefixSum[l1];

      for (int l2 = 0; l2 < n; l2++) {
        if (l2 >= l1 && l2 < r1) continue;

        for (int r2 = l2; r2 < n; r2++) {
          if (r2 >= l1 && r2 < r1) continue;

          long long sum2 = prefixSum[r2 + 1] - prefixSum[l2];

          if (sum1 == sum2) {
            return true;
          }
        }
      }
    }
  }

  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    if (canPrint(arr)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
