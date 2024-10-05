#include <bitset>
#include <iostream>

using namespace std;

const int MAX_w = 6250001;

int main() {
  int n, w;
  cin >> n >> w;
  bitset<MAX_w> demon_programming;
  demon_programming[0] = 1;
  for (int i = 0; i < n; ++i) {
    int weight;
    cin >> weight;
    demon_programming |= (demon_programming << weight);
  }
  if (demon_programming[w]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
