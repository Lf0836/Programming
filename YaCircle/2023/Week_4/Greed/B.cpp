#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> repairTimes(k);
  for (int i = 0; i < k; ++i) {
    std::cin >> repairTimes[i];
  }

  std::sort(repairTimes.begin(), repairTimes.end());

  int maxRepairs = 0;
  int totalTime = 0;
  for (int i = 0; i < k; ++i) {
    totalTime += repairTimes[i];
    if (totalTime <= n) {
      maxRepairs++;
    } else {
      break;
    }
  }

  std::cout << maxRepairs << std::endl;

  return 0;
}