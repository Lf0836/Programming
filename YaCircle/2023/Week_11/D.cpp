#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int s;
  cin >> s;
  int elms[s];
  for (int i = 0; i < s; i++) {
    elms[i] = i + 1;
  }
  sort(elms, elms + s);
  do {
    for (int i = 0; i < s; i++) {
      cout << elms[i];
      if (i == s - 1) {
        cout << endl;
      }
    }
  } while (next_permutation(elms, elms + s));
  return 0;
}
