#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long n, k, x;
  cin >> n >> k >> x;
  vector<long> arr(n);
  for (long i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  long bigerst = 0;
  for (long i = 0; i < n; i++) {
    long sum = 0;
    long counter = 0;
    for (long j = i; j < n; j++) {
      sum += arr[j];
      counter++;
      if (counter % k == 0) {
        sum -= x;
      }
      if (sum > bigerst) {
        bigerst = sum;
      }
    }
  }

  cout << bigerst << endl;
  return 0;
}
