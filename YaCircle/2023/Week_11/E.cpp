#include <iostream>
#include <string>

using namespace std;

void func(int n, int k, string s) {
  if (n < k) {
    return;
  }
  if (k == 0) {
    cout << s << endl;
  } else {
    func(n - 1, k, s);
    func(n - 1, k - 1, s + to_string(n) + " ");
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  func(n, k, "");
}
