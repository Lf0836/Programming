#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  int k;
  cin >> s >> k;
  int minlen = 0;
  int maxlen = 0;
  int baselen = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == '*' || s[i] == '?') {
      minlen--;
      if (s[i] == '*') {
        maxlen += 200;
      }
    } else {
      minlen++;
      maxlen++;
    }
  }
  if (k < minlen || k > maxlen) {
    cout << "Impossible" << endl;
    return 0;
  }
  string ans = "";
  int curleng = minlen;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == '*' || s[i] == '?') {
      continue;
    }
    if (i + 1 < s.length() && s[i + 1] == '*') {
      while (curleng < k) {
        ans += s[i];
        curleng++;
      }
    } else if (i + 1 < s.length() && s[i + 1] == '?') {
      if (curleng < k) {
        ans += s[i];
        curleng++;
      }
    } else {
      ans += s[i];
    }
  }
  cout << ans << endl;
  return 0;
}
