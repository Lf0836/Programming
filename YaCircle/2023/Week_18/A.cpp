#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> ComZFun(string string) {
    int n = string.size();
    vector<int> ZFun(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            ZFun[i] = min(r - i + 1, ZFun[i - l]);
        }
        while (i + ZFun[i] < n && string[ZFun[i]] == string[i + ZFun[i]]) {
            ZFun[i]++;
        }
        if (i + ZFun[i] - 1 > r) {
            l = i;
            r = i + ZFun[i] - 1;
        }
    }
    return ZFun;
}

int main() {
    string string;
    cin >> string;
    vector<int> res = ComZFun(string);
    res[0] = string.size();
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size() - 1) {
            cout << " ";
        }
    }
    return 0;
}
