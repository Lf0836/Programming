#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<long long> arr;
  long long num;
  while (cin >> num) {
    arr.push_back(num);
    if (num == 0) {
      break;
    }
  }
  reverse(arr.begin(), arr.end());
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
}
