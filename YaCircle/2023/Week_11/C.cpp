#include <iostream>
#include <vector>

using namespace std;

void Bnum_generater(int id, int s, char* res, int ost) {
  if (id == s) {
    puts(res);
  }
  if (id != s) {
    if ((s - id) > ost) {
      res[id] = '0';
      Bnum_generater(id + 1, s, res, ost);
    }
    if (ost > 0) {
      res[id] = '1';
      Bnum_generater(id + 1, s, res, ost - 1);
    }
  }
}

int main() {
  int s, Count;
  cin >> s >> Count;
  vector<char> res(s + 1);
  res[s] = '\0';
  Bnum_generater(0, s, res.data(), Count);
  return 0;
}
