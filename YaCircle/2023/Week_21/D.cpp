#include <iostream>
#include <vector>

using namespace std;

struct MHP {
    int MC;
    vector <long long> arr;
    MHP(int n) {
        MC = n;
    }
    pair <int, long long> MEX() {
        if (arr.size() == 0) {
            return pair <int, long long> (-1, -1);
        }
        pair <int, long long> res = {1, arr[0]};
        arr[0] = arr.back();
        arr.pop_back();
        int curr = 0;
        if (arr.size() == 0) {
            res.first = -2;
            return res;
        }
        while (2 * curr + 1 < arr.size()) {
            int maxP;
            if (2 * curr + 1 == arr.size() - 1) {
                maxP = 2 * curr + 1;
            } else {
                maxP = (arr[2 * curr + 1] >= arr[2 * curr + 2] ? 2 * curr + 1 : 2 * curr + 2);
            }
            if (arr[curr] < arr[maxP]) {
                swap(arr[curr], arr[maxP]);
                curr = maxP;
                res.first = maxP + 1;
            } else {
                break;
            }
        }
        return res;
    }
    int adder(long long num) {
        if (arr.size() == MC) {
            return -1;
        }
        int curr = arr.size();
        arr.push_back(num);
        while (curr > 0 && arr[(curr - 1) / 2] < arr[curr]) {
            swap(arr[(curr - 1) / 2], arr[curr]);
            curr = (curr - 1) / 2;
        }
        return curr + 1;
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    MHP heap(n);
    for (int i = 0; i < m; ++i) {
        int comand;
        cin >> comand;
        if (comand == 1) {
            pair <int, long long> res = heap.MEX();
            if (res.first == -1) {
                cout << -1 << endl;
            } else if (res.first == -2) {
                cout << 0 << " " << res.second << endl;
            } else {
                cout << res.first << " " << res.second << endl;
            }
        } else {
            long long num;
            cin >> num;
            cout << heap.adder(num) << endl;
        }
    }
    for (int i = 0; i < heap.arr.size(); ++i) {
        cout << heap.arr[i] << " ";
    }
    return 0;
}
