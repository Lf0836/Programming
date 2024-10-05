#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x;
    cin >> x;
    int count = 0;
    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
            count += 2;
        }
        if (i * i == x) {
            count -= 1;
        }
    }
    cout << count;
    return 0;
}
