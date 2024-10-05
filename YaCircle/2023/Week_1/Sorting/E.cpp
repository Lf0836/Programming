#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  int shift = 10001;
  cin >> n;
  vector<int> arr(shift * 2, -shift);
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    arr[num + shift]++;
  }
  for (int i = 0; i < shift * 2; i++) {
    if (arr[i] != -shift) {
      for (int j = 0; j < arr[i] + shift; j++) {
        cout << i - shift << " ";
      }
    }
  }
}
