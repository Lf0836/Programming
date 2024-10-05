#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a.push_back(x);
  }
  for (int i = n; i > 0; i--) {
    cout << a[i - 1] << " ";
  }
}
