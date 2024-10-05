#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    char c;
    int a, b;
    cin >> a >> c >> b;
    if (a == 0 || b == 0) {
        cout << 0;
        return 0;
    } else {
        cout << min(min(a, b), (a + b - 1) / 2);
    }
    return 0;
}