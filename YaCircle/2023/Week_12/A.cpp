#include <iostream>
#include <vector>

using namespace std;

void fibana(vector<int> &curr, int n) {
    if (int(curr.size()) == n) {
        for (int i = 0; i < n; i++) {
            cout << curr[i];
        }
        cout << endl;
        return;
    }
    curr.push_back(0);
    fibana(curr, n);
    curr.pop_back();
    curr.push_back(1);
    fibana(curr, n);
    curr.pop_back();
}
int main() {
    int n;
    cin >> n;
    vector<int> curr;
    fibana(curr, n);
    return 0;
}
