#include <iostream>

using namespace std;

int main() {
    long long Xone, Yone, Xtwo, c;
    cin >> Xone >> Yone >> Xtwo >> c;
    cout << (Xone ^ Yone) << endl;
    long long Ytwo = 0;
    for (int i = 0; i < 32; i++) {
        if (!((Xtwo >> i) & 1) && ((c >> i) & 1)) {
            Ytwo |= (1 << i);
        }
        if (((Xtwo >> i) & 1) && !((c >> i) & 1)) {
            Ytwo |= (1 << i);
        }
    }
    cout << Ytwo << endl;
    return 0;
}
