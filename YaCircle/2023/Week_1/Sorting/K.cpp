#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int NW, n;
    cin >> NW >> n;
    int counter = 0;
    int LP = NW;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        if (arr[i] >= NW && counter == 0) {
            counter++;
            LP = arr[i];
        }
        if (arr[i] - LP > 2 && !counter == 0) {
            LP = arr[i];
            counter++;
        }
    }
    cout << counter;
}
