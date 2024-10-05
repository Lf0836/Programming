#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int fac = 2; n > 1; fac++) {
        int pow = 0;
        while (n % fac == 0) {
            n /= fac;
            pow++;
        }
        if (pow > 0) {
            cout << fac;
            if (pow > 1) {
                cout << "^" << pow;
            }
            if (n > 1) {
                cout << "*";
            }
        }
    }
    return 0;
}
