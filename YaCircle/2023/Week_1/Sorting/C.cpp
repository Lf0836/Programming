#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> array;
  int num;

  for (int i = 0; i < n; i++) {
    cin >> num;
    array.push_back(num);
  }

  for (int i = 0; i < n - 1; i++) {
    int min = 1001;
    int index;
    for (int j = i; j < n; j++) {
      if (array[j] < min) {
        min = array[j];
        index = j;
      }
    }
    array.erase(array.begin() + index);
    array.insert(array.begin() + i, min);
  }

  for (int i = 0; i < n; i++) {
    cout << array[i] << " ";
  }
}
