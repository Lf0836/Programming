#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  int numElements, maxDiff, allowedDiff;
  cin >> numElements >> maxDiff >> allowedDiff;
  vector<int> values(numElements);
  for (int idx = 0; idx < numElements; idx++) {
    cin >> values[idx];
  }
  int maxLength = 0;
  unordered_map<int, vector<int>> indexMap;
  for (int idx = 0; idx < numElements; idx++) {
    indexMap[values[idx]].push_back(idx);
  }
  for (const auto& entry : indexMap) {
    int start = 0, end = 0;
    vector<int> indices = entry.second;
    int totalIndices = indices.size();
    while (end < totalIndices) {
      int currentLength = end - start + 1;
      int range = indices[end] - indices[start] + 1;
      if (range - currentLength <= allowedDiff) {
        maxLength = max(maxLength, currentLength);
        end++;
      } else {
        start++;
      }
    }
  }
  cout << maxLength << endl;
  return 0;
}
