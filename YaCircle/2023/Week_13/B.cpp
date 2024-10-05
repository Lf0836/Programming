#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < m; i++) {
        int tX, tY;
        cin >> tX >> tY;
        arr[tX-1]++;
        arr[tY-1]++;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}
