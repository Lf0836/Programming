#include <iostream>

using namespace std;

int main() {
  bool res;
  for (int x = 0; x < 2; x++) {
    for (int y = 0; y < 2; y++) {
      for (int z = 0; z < 2; z++) {
        res = (x & y) | (!y & !z);
        cout << y << " " << x << " " << z << " | " << res << endl;
      }
    } 
  }
  return 0;
} 