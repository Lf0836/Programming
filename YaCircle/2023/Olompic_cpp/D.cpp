#include <iostream>
#include <vector>

using namespace std;

int count_corner_sofas(vector<string> corridor) {
  int count = 0;
  for (int i = 0; i < corridor[0].size() - 1; i++) {
    if (corridor[0][i] == '0' && corridor[0][i + 1] == '0' &&
        corridor[1][i] == '0') {
      count++;
      corridor[0][i] = 'X';
      corridor[0][i + 1] = 'X';
      corridor[1][i] = 'X';
    } else if (corridor[0][i] == '0' && corridor[0][i + 1] == '0' &&
               corridor[1][i + 1] == '0') {
      count++;
      corridor[0][i] = 'X';
      corridor[0][i + 1] = 'X';
      corridor[1][i + 1] = 'X';
    } else if (corridor[1][i] == '0' && corridor[1][i + 1] == '0' &&
               corridor[0][i + 1] == '0') {
      count++;
      corridor[1][i] = 'X';
      corridor[1][i + 1] = 'X';
      corridor[0][i + 1] = 'X';
    } else if (corridor[1][i] == '0' && corridor[1][i + 1] == '0' &&
               corridor[0][i] == '0') {
      count++;
      corridor[1][i] = 'X';
      corridor[1][i + 1] = 'X';
      corridor[0][i] = 'X';
    }
  }
  return count;
}

int main() {
  vector<string> corridor(2);
  for (int i = 0; i < 2; i++) {
    cin >> corridor[i];
  }
  int result = count_corner_sofas(corridor);
  cout << result << endl;
  return 0;
}
