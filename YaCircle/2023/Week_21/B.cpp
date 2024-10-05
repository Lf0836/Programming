#include <iostream>
#include <vector>

using namespace std;

int sift_down_please(vector<int>& arr, int index) {
    int n = arr.size();
    while (2 * index + 2 < n) {
        if (arr[2 * index + 1] > arr[index] && arr[2 * index + 1] > arr[2 * index + 2]) {
            swap(arr[index], arr[2 * index + 1]); index = 2 * index + 1;
            continue;
        }
        if (arr[2 * index + 2] > arr[index] && arr[2 * index + 1] < arr[2 * index + 2]) {
            swap(arr[index], arr[2 * index + 2]); index = 2 * index + 2;
            continue;
        }
        if (arr[index] > arr[2 * index + 1] && arr[index] > arr[2 * index + 2]) {
            return index;
        }
    }
    if (arr[index] < arr[n - 1] && 2 * index + 2 == n) {
        swap(arr[n - 1], arr[index]);
        index = n - 1;
    }
    return index;
}

int main() {
    int n, m, k, add;
    cin >> n;
    vector<int> arr(n);
    for (int j = 0; j < n; ++j) {
        cin >> arr[j];
    }
    cin >> m;
    vector<int> a(m);
    int z = m;
    for (; m > 0; --m) {
        cin >> k;
        cin >> add;
        arr[k - 1] = arr[k - 1] - add;
        a[z - m] = sift_down_please(arr, k - 1);
    }
    for (int i = 0; i < z; ++i) {
        cout << a[i] + 1 << endl;
    }
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    return 0;
}
