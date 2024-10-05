#include <iostream>
#include <vector>

using namespace std;

const long long inf = 1e9;
long double eps = 1e-9;
vector<long long> h, p, h1, p1;
long long b = 54;
long long M = 1e9 + 7;

long long get(long long l, long long r) {
    return (h[r + 1] - (h[l] * p[r - l + 1]) % M + M) % M;
}

long long get_one(long long l, long long r) {
    return (h1[r + 1] - (h1[l] * p1[r - l + 1]) % M + M) % M;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, t, t1;
    cin >> t1 >> s;
    if (t1 == s) {
        cout << 0;
        return 0;
    }
    t = t1;
    t += t1;
    long long n = t.size();
    h.resize(n + 1);
    p.resize(n + 1);
    long long len, i;
    h[0] = 0;
    p[0] = 1;
    for (i = 0; i < n; i++) {
        h[i + 1] = (h[i] * b + (t[i] - 'a' + 1)) % M;
        p[i + 1] = (p[i] * b) % M;
    }
    n = s.size();
    h1.resize(n + 1);
    p1.resize(n + 1);
    h1[0] = 0;
    p1[0] = 1;
    for (i = 0; i < n; i++) {
        h1[i + 1] = (h1[i] * b + (s[i] - 'a' + 1)) % M;
        p1[i + 1] = (p1[i] * b) % M;
    }
    long long ep = s.size();
    for (i = 0; i <= t.size() - ep; i++) {
        if (get(i, i + ep - 1) == get_one(0, ep - 1)) {
            cout << s.size() - i;
            return 0;
        }
    }
    cout << "-1";
    return 0;
}
