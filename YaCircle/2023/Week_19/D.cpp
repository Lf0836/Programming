#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isAnagram(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) {
        return false;
    }
    vector<int> counts(26);
    for (int i = 0; i < a.size(); i++) {
        counts[a[i] - 1]++;
        counts[b[i] - 1]--;
    }
    for (int count : counts) {
        if (count != 0) {
            return false;
        }
    }
    return true;
}

int findMaxAnagramLength(const vector<int>& a, const vector<int>& b) {
    int maxLength = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = i; j < a.size(); j++) {
            if (isAnagram(vector<int>(a.begin() + i, a.begin() + j + 1), vector<int>(b.begin(), b.begin() + j + 1 - i))) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    cout << findMaxAnagramLength(a, b) << endl;
    return 0;
}
