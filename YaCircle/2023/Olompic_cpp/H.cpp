#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  int m;
  cin >> m;
  vector<int> s(m);
  unordered_set<int> s_set;
  for (int i = 0; i < m; i++) {
    cin >> s[i];
    s_set.insert(s[i]);
  }
  vector<int> result;
  for (int i = 0; i < m; i++) {
    result.push_back(s[i]);
    for (int j = i + 1; j < m; j++) {
      int next_gcd = gcd(s[i], s[j]);
      if (s_set.find(next_gcd) == s_set.end()) {
        cout << -1 << endl;
        return 0;
      }
      result.push_back(next_gcd);
    }
  }
  cout << result.size() << endl;
  for (int num : result) {
    cout << num << " ";
  }
  return 0;
}