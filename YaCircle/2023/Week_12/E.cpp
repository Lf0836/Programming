#include <iostream>

using namespace std;

long long func(long long n) {
    if (n == 0) {
      return 0;
    } else if (n == 1) {
        return 1;
    } else if (n % 2 == 0) {
        return func(n / 2);
    } else {
        return func(n / 2) + func(n / 2 + 1);
    }
}

int main() {
    long long n;
    cin >> n;
    cout << func(n);
    return 0;
}
