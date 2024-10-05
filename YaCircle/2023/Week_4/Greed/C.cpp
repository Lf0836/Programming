#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long res;
  int num;
  long long counter = 0;
  std::multiset<long long> mulset;
  for (int i = 0; i < n; i++) {
    cin >> num;
    mulset.insert(num);
  }
  while (mulset.size() > 1) {
    auto it = mulset.begin();
    auto it2 = mulset.begin();
    it2++;
    res = *it + *it2;
    counter += res;
    mulset.erase(it);
    mulset.erase(it2);
    mulset.insert(res);
  }
  cout << counter << endl;
  return 0;
}
