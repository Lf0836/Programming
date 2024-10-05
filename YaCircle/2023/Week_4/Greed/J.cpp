#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  int crC = 0;
  char crCh = '1';
  int cC = 0;
  vector<vector<char>> arr(n, vector<char>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] == 'C') {
        cC++;
      }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (arr[i][j] == 'C') {
          crC++;
        }
        arr[i][j] = crCh;
        cout << arr[i][j];
        if (crC >= cC / 2) {
          crCh = '2';
        }
      }
      cout << endl;
    }
    return 0;
  }
