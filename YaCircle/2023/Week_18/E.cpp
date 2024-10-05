#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

string s, revS;

vector<int> zumba(string &s) {
    int n = s.size();
    vector<int> zumba(n, 0);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            zumba[i] = min(r - i + 1, zumba[i - l]);
        while (i + zumba[i] < n && s[zumba[i]] == s[i + zumba[i]])
            zumba[i]++;
        if (i + zumba[i] - 1 > r)
            l = i, r = i + zumba[i] - 1;
    }
    return zumba;
}


int main() {
    int n;
    cin >> n;
    cin >> s;
    revS = s;
    reverse(revS.begin(), revS.end());
    s = s + revS;
    vector<int> res = zumba(s);
    for (int i = res.size() - 1; i >= s.size() / 2; i--)
        cout << res[i] << " ";
    cout << endl;
}
