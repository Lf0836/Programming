#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> fibana(n + 1);
  fibana[0] = 0;
  fibana[1] = 1;
  for (int i = 2; i <= n; i++) {
    fibana[i] = fibana[i - 1] + fibana[i - 2];
  }
  cout << fibana[n] << endl;
  return 0;
}
