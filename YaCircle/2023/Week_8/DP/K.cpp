#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> lst(n);
    for (int i = 0; i < n; i++) {
        cin >> lst[i];
    }
    sort(lst.begin(), lst.end());
    vector<int> d(n);
    d[1] = lst[1] - lst[0];
    if (n > 2) {
        d[2] = lst[2] - lst[0];
        for (int i = 3; i < n; i++) {
            d[i] = min(d[i - 2], d[i - 1]) + lst[i] - lst[i - 1];
        }
    }
    cout << d[n - 1] << endl;
    return 0;
}
