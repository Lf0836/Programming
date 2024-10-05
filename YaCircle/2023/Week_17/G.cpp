// #include <iostream>
// #include <bitset>
// #include <set>

// using namespace std;

// int main() {
//   long n, sum;
//   cin >> n;
//   set<long> not_our;
//   for (long i = 0; i < n; i++) {
//     bitset<60> bit_N(i);
//     for (long j = 0; j < 60; j++) {
//       sum += bit_N[j];
//     }
//     if (i + sum <= n) {
//       not_our.emplace_hint(not_our.end(), i + sum);
//     }
//     sum = 0;
//   }
//   cout << n - not_our.size() + 1;
//   return 0;
// }
#include <iostream>
#include <bitset>
#include <set>

using namespace std;

int main() {
  long n, sum = 0;
  cin >> n;
  set<long> not_our;
  for (long i = 0; i < n; i++) {
    bitset<60> bit_N(i);
    sum = bit_N.count();
    if (i + sum <= n) {
      not_our.emplace_hint(not_our.end(), i + sum);
    }
  }
  cout << n - not_our.size() + 1;
  return 0;
}
