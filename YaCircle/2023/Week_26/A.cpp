#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  bool hasOddGroup = false;
  long long totalSize = 0;
  int oddGroupIndex = 0;
  int oddGroupLeft = 0;
  int oddGroupRight = 0;
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    int size = r - l + 1;
    totalSize += size;
    if (size % 2 == 1) {
      hasOddGroup = true;
      oddGroupIndex = i + 1;
      oddGroupLeft = l;
      oddGroupRight = r;
    }
  }
  if (totalSize % 2 == 1 || hasOddGroup) {
    cout << "Win\n";
    if (hasOddGroup) {
      cout << oddGroupLeft << " " << (oddGroupLeft + oddGroupRight) / 2 << "\n";
    } else {
      cout << "1 2\n";
    }
  } else {
    cout << "Lose\n";
  }
  return 0;
}
