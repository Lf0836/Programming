#include <iostream>

bool isItPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

using namespace std;

int main() {
    int num;
    cin >> num;
    if (isItPrime(num)) {
        cout << "prime";
    } else {
        cout << "composite";
    }
    return 0;
}
