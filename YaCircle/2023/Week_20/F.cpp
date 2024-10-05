#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int l, n;
    cin >> l >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a.insert(a.begin(), 0);
    a.push_back(l);
    n += 2;
    vector <vector <int>> dp(n, vector <int> (n, 0));
    for (int j = 1; j < n; ++j) {
        for (int i = j - 2; i >= 0; --i) {
            dp[i][j] = 1000000000;
            for (int k = i + 1; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
            dp[i][j] += a[j] - a[i];
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}