#include <iostream>
#include <set>
#include <vector>

using namespace std;

long findSubarray(const vector<long>& nums, long k) {
  long n = nums.size();
  long start = -1;
  set<long> targetSet;
  for (long i = 1; i <= k; i++) {
    targetSet.insert(i);
  }
  set<long> currentSet;
  for (long i = 0; i < n; i++) {
    currentSet.insert(nums[i]);
    if (currentSet == targetSet) {
      return i - k + 2;
    }
    if (currentSet.size() > k) {
      currentSet.erase(nums[i - k + 1]);
    }
  }
  return start;
}

int main() {
  long n, k;
  cin >> n >> k;
  vector<long> a(n);
  for (long i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << findSubarray(a, k) << endl;
  return 0;
}
