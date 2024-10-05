#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> array(n);
  int num;

  for (int i = 0; i < n; i++) {
    cin >> array[i];
  }

  for (int i = 0; i < n - 1; i++) {
    int count_swap = 0;
    for (int j = 0; j < n - 1 - i; j++) {
      if (array[j] > array[j + 1]) {
        swap(array[j], array[j + 1]);
        count_swap++;
      }
    }
    if (count_swap == 0) {
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << array[i] << " ";
  }
}
