#include <bitset>
#include <iostream>

using namespace std;

int main() {
  int A, i;
  cin >> A >> i;
  bitset<32> binary(A);
  binary.flip(i);
  cout << binary.to_ulong() << endl;
  return 0;
}
