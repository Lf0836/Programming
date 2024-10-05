#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> pointcost(n, vector<int>(m));
    int i = 0;
    while (i < n) {
        int j = 0;
        while (j < m) {
            cin >> pointcost[i][j];
            j++;
        }
        i++;
    }
    int greeds;
    cin >> greeds;
    vector<int> greed(greeds);
    int k = 0;
    while (k < greeds) {
        cin >> greed[k];
        k++;
    }
    sort(greed.rbegin(), greed.rend());
    int orders = 0;
    vector<bool> used(greeds, false);
    i = 0;
    while (i < n) {
        int j = 0;
        while (j < m) {
            int l = 0;
            while (l < greeds) {
                if (!used[l] && pointcost[i][j] >= greed[l]) {
                    used[l] = true;
                    orders++;
                    break;
                }
                l++;
            }
            j++;
        }
        i++;
    }

    cout << orders << endl;

    return 0;
}