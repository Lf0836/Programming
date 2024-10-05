#include <iostream>

using namespace std;

int main() {
  string str;
  cin >> str;
  for (char i = 97; i < 123; i++) {
    int counter = 0;
    for (char c : str) {
      if (c == i) {
        counter++;
      }
    }
    cout << counter << " ";
  }
}
