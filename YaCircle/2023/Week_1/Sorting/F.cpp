#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string word_one, word_two, result;
  cin >> word_one >> word_two;
  sort(word_one.begin(), word_one.end());
  sort(word_two.begin(), word_two.end());

  if (word_one == word_two) {
    result = "YES";
  } else {
    result = "NO";
  }
  cout << result;
}
