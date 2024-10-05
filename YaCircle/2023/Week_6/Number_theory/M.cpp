#include <iostream>

using namespace std;

int gcd(int n2, int m2) {
    while (m2) {
        int t = m2;
        m2 = n2 % m2;
        n2 = t;
    }
    return n2;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << gcd(n - 1, m - 1) + 1;
    return 0;
}
