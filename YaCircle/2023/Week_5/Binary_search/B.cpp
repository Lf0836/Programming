#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BS(const vector<int>& arr, int target) {
    int L = 0;
    int H = arr.size() - 1;
    while (L <= H) {
        int M = (L + H) / 2;
        if (arr[M] == target) {
            return arr[M];
        }
        if (arr[M] < target) {
            L = M + 1;
        } else {
            H = M - 1;
        }
    }
    if (H < 0) {
        return arr[0];
    }
    if (L >= arr.size()) {
        return arr[arr.size() - 1];
    }
    int D1 = abs(target - arr[H]);
    int D2 = abs(target - arr[L]);
    if (D1 <= D2) {
        return arr[H];
    } else {
        return arr[L];
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        cout << BS(arr, temp) << endl;
    }
    return 0;
}
