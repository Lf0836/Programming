#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int SB = ceil(sqrt(n));
    vector<int> MB(n / SB + 1, numeric_limits<int>::min());
    for (int i = 0; i < n; i++) {
        MB[i / SB] = max(MB[i / SB], arr[i]);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        int MR = numeric_limits<int>::min();
        for (int j = l - 1; j < r;) {
            if (j % SB == 0 && j + SB - 1 < r) {
                MR = max(MR, MB[j / SB]);
                j += SB;
            } else {
                MR = max(MR, arr[j]);
                j++;
            }
        }
        cout << MR << " ";
    }
    return 0;
}
