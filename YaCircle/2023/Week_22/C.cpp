#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int BS = ceil(sqrt(n));
    vector<int> ZB(n / BS + 1, 0);
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            ZB[i / BS]++;
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        int CZ = 0;
        for (int j = l - 1; j < r;) {
            if (j % BS == 0 && j + BS - 1 < r) {
                CZ += ZB[j / BS];
                j += BS;
            } else {
                if (arr[j] == 0) {
                    CZ++;
                }
                j++;
            }
        }
        cout << CZ << " ";
    }
    return 0;
}
