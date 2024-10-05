#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void printFactors(int n, int m, vector<int>& factors, int prev) {
  if (n == 1) {
    for (int i = 0; i < factors.size(); i++) {
      if (i != 0) {
        cout << "*";
      }
      cout << factors[i];
    }
    cout << endl;
    return;
  }
  for (int i = m; i <= n; i++) {
    if (n % i == 0) {
      if (i >= prev) {
        factors.push_back(i);
        printFactors(n / i, i, factors, i);
        factors.pop_back();
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> factors;
  printFactors(n, m, factors, m);
  return 0;
}
