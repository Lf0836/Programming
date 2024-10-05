#include <bits/stdc++.h>

using namespace std;

vector <int>  Done,  Dtwo;

void Func(string s) {
    int n = s.size();
     Done.resize(n);
     Dtwo.resize(n);
    for (int i = 0, lett = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(Done[lett + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
         Done[i] = k--;
        if (i + k > r) {
            lett = i - k;
            r = i + k;
        }
    }
    for (int i = 0, lett = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(Dtwo[lett + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
         Dtwo[i] = k--;
        if (i + k > r) {
            lett = i - k - 1;
            r = i + k;
        }
    }
}

int main() {
    string str;
    cin >> str;
    Func(str);
    long long res = 0;
    for (int i = 0; i < str.size(); i++) {
        res +=  Done[i] +  Dtwo[i];
    }
    cout << res << endl;
}
