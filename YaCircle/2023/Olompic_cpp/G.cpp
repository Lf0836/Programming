#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
  int n;
  cin >> n;
  unordered_set<string> altushka_names;
  for (int i = 0; i < n; ++i) {
    string sample;
    cin >> sample;
    unordered_set<char> unique_chars;
    for (char c : sample) {
      unique_chars.insert(c);
    }
    if (unique_chars.size() == 25) {
      altushka_names.insert(sample);
    }
  }
  cout << altushka_names.size() << endl;
  return 0;
}
