#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int count = 0;
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
        count++;
    }
    cout << count + 1 << endl;
}
