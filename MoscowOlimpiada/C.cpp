#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isBeautiful(int d, int m, int y) {
  vector<long> nums(10);
  string result = to_string(d) + to_string(m) + to_string(y);
  for (long i = 0; i < result.size(); i++) {
    nums[result[i]]++;
  }
  for (long j = 0; j < result.size(); j++) {
    if (result[j] > 1) {
      return false;
    }
  }
  return true;
}


int main() {
  long d, m, y;
  cin >> d >> m >> y;
  vector<vector<long>> nums(10);
  
  // string dataInGoodMood = to_string(d) + to_string(m) + to_string(y);
  // for (long i = 0; i < dataInGoodMood.size(); i++) {
  //   nums[dataInGoodMood[i]].push_back(i);
  // }
  // for (long i = dataInGoodMood.size() - 1; i >= 0; i--) {
  //   if (nums[dataInGoodMood[i]].size() != 1) {
  //     for (long j = nums[dataInGoodMood[i]].size(); j > 0; j--) {
  //       dataInGoodMood[i]++;
  //       if (dataInGoodMood[i] > 9) {
  //         dataInGoodMood[i - 1]++;
  //         dataInGoodMood[i] = 0;
  //       }
  //       i = dataInGoodMood.size() - 1;
  //       j = nums[dataInGoodMood[i]].size();
  //     }
  //   }
  // }
  return 0;
}