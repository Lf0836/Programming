#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  set<char> all_digits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  for (char c : s) {
    all_digits.erase(c);
  }
  cout << *all_digits.begin() << endl;
  return 0;
}
