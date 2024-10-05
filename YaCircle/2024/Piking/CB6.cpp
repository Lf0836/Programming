#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long a, b, c, dels, ans = 0;
    cin >> a >> b >> c;
    for (int i = 1; i > 0; i++) {
      dels = min(c, b / 2);
      if (dels > 0) {
        c -= dels;
        b -= dels * 2;
        ans += dels;
      } else {
        break;
      }
    }
    for (int i = 1; i > 0; i++) {
      dels = min(b / 2, a / 2);
      if (dels > 0) {
        b -= dels * 2;
        a -= dels * 2;
        ans += dels;
      } else {
        break;
      }
    }
    for (int i = 1; i > 0; i++) {
      dels = min(a, c / 2);
      if (dels > 0) {
        c -= dels * 2;
        a -= dels;
        ans += dels;
      } else {
        break;
      }
    }
    for (int i = 1; i > 0; i++) {
      dels = min(c, a / 3);
      if (dels > 0) {
        c -= dels;
        a -= dels * 3;
        ans += dels;
      } else {
        break;
      }
    }
    for (int i = 1; i > 0; i++) {
      dels = a / 5;
      if (dels > 0) {
        a -= dels * 5;
        ans += dels;
      } else {
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}