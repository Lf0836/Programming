#include <iostream>
#include <string>

using namespace std;

void func(int n, string str) {
  if (str.length() == n) {
    cout << str << endl;
    return;
  }
  func(n, str + "0");
  func(n, str + "1");
}

int main() {
  int n;
  cin >> n;
  func(n, "");
  return 0;
}
