#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  map<char, int> mapa = {{'W', 0}, {'S', 0}, {'E', 0}, {'N', 0}};
  for (int i = 0; i < s.size(); i++) {
    mapa[s[i]]++;
  }
  if ((mapa['W'] == 0 && mapa['E'] != 0)(mapa['W'] != 0 && mapa['E'] == 0)) {
    cout << "No" << endl;
  } else if ((mapa['S'] == 0 && mapa['N'] != 0)(mapa['S'] != 0 && mapa['N'] == 0)) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}