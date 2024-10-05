#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> arr;
    cin >> n;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr.push_back(num);
    }
    for (int i = 1; i < n; i++) {
        int nowmoment = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > nowmoment) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = nowmoment;
    }
        for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}