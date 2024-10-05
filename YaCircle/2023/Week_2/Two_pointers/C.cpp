#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> arrey(n);
    for (int i = 0; i < arrey.size(); i++) {
        cin >> arrey[i].first >> arrey[i].second;
    }
    sort(arrey.begin(), arrey.end());

    vector<pair<int, int>> res;
    res.push_back(arrey[0]);
    int i = 1;
    while (i < n) {
        if (arrey[i].first <= res.back().second) {
            res.back().second = max(res.back().second, arrey[i++].second);
        } else {
            res.push_back(arrey[i++]);
        }
    }
    cout << res.size() << endl;
    for (unsigned long long i = 0; i < res.size(); i++) {
        cout << res[i].first << " " << res[i].second << endl;
    }
    return 0;
}  