#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  vector<int> arr;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    arr.push_back(temp);
  }

  sort(arr.begin(), arr.end());
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}
