#include <iostream>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  long long KarrafeCundolle[k] = {0};
  for (int i = 1; i <= n; i++) {
    KarrafeCundolle[i % k]++;
  }
  long long ans = 0;
  for (int i = 0; i < k; i++) {
    int j = (k - i) % k;
    int l = (k - i) % k;
    if ((i + j) % k == 0 && (j + l) % k == 0 && (i + l) % k == 0) {
      ans += KarrafeCundolle[i] * KarrafeCundolle[j] * KarrafeCundolle[l];
    }
  }
  cout << ans << endl;
  return 0;
}
