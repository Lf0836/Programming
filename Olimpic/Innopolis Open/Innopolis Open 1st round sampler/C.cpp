#include<iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        res += a;
    }
    cout << res << endl;
    return 0;
}
