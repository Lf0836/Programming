#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> nums;
  nums.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  unordered_map<int, int> lind;
  for (int i = 0; i < n; i++) {
    lind[nums[i]] = i;
  }
  vector<int> res;
  for (int i = 0; i < n; i++) {
    if (lind[nums[i]] == i) {
      res.push_back(nums[i]);
    }
  }
  cout << res.size() << endl;
  for (int num : res) {
    cout << num << " ";
  }
  return 0;
}