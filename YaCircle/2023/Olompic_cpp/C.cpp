#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long getMaxRelaxation(const vector<int>& relaxationCoefficients) {
  int n = relaxationCoefficients.size();
  vector<long long> maxRelaxation(n, 0);
  for (int i = n - 1; i >= 0; --i) {
    int nextCity = i + relaxationCoefficients[i];
    maxRelaxation[i] = relaxationCoefficients[i];
    if (nextCity < n) {
      maxRelaxation[i] += maxRelaxation[nextCity];
    }
  }
  return *max_element(maxRelaxation.begin(), maxRelaxation.end());
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> relaxationCoefficients(n);
    for (int i = 0; i < n; ++i) {
      cin >> relaxationCoefficients[i];
    }
    cout << getMaxRelaxation(relaxationCoefficients) << endl;
  }
  return 0;
}
