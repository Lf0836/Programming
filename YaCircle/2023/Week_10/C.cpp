#include <iostream>

using namespace std;

const long long Mod = 1000000007;

long long power(long long base, long long exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % Mod;
        }
        base = (base * base) % Mod;
        exponent /= 2;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    long long result = (power(3, 3 * n) - power(7, n)) % Mod;
    if (result < 0) {
        result += Mod;
    }
    cout << result << endl;
    return 0;
}
