#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<long long> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    vector<long long> dp(n);
    int minStart = 0;
    for (int i = 1; i < n; i++) {
        if (t[i] < t[minStart]) {
            minStart = i;
        }
    }
    dp[minStart] = t[minStart];
    for (int i = minStart + 1; i < n; i++)
        dp[i] = min(t[i], dp[i - 1] + s[i - 1]);

    dp[0] = min(t[0], dp[n - 1] + s[n - 1]);
    for (int i = 1; i < n; i++) {
        dp[i] = min(t[i], dp[i - 1] + s[i - 1]);
    }
    for (auto i : dp) {
        cout << i << '\n';
    }
    return 0;
}
