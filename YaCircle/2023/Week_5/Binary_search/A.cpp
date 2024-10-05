#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arrN(n);
    for (int i = 0; i < n; i++) {
        cin >> arrN[i];
    }
    vector<int> arrK(k);
    for (int i = 0; i < k; i++) {
        cin >> arrK[i];
        int L = 0;
        int R = n;
        while (R - L > 1) {
            int m = L + (R - L) / 2;
            if (arrK[i] < arrN[m]) {
                R = m;
            } else {
                L = m;
            }
        }
        if (arrK[i] == arrN[L]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}