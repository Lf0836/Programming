#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr1(n);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;
    vector<int> arr2(m);
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    unordered_map<int, int> countMap;
    for (int num : arr1) {
        countMap[num]++;
    }

    vector<int> result;
    for (int num : arr2) {
        result.push_back(countMap[num]);
    }

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
