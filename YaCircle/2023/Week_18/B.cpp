#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long> pref_func(string s) {
  vector<long> vec(s.length(), 0);
  for (long i = 1; i < s.length(); i++) {
    long j = vec[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = vec[j - 1];
    }
    if (s[i] == s[j]) {
      vec[i] = j + 1;
    } else {
      vec[i] = j;
    }
  }
  return vec;
}

int main() {
  string str;
  cin >> str;
  vector<long> vex = pref_func(str);
  for (long i = 0; i < vex.size(); i++) {
    cout << vex[i] << ' ';
  }
}