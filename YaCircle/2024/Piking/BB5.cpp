#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  string str;
  cin >> str;
  unordered_map<char, ll> freaks;
  for (char c : str) {
    freaks[c]++;
  }
  ll len = str.length();
  ll ans = len * (len - 1) / 2 + 1;
  for (const auto& pair : freaks) {
    ll count = pair.second;
    ans -= count * (count - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
