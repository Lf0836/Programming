#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n;
    int counter = 1;
    cin >> n;
    vector<int> heights(n);
    vector<int> st1;
    vector<int> st2;
    vector<int> act;
    for (int i = 0; i < n; i++)
        cin >> heights[i];
    st1.push_back(heights[0]);
    for (int i = 1; i < n; i++) {
        if (st1.back() > heights[i]) {
            st1.push_back(heights[i]);
            counter++;
        } else {
            act.push_back(1);
            act.push_back(counter);
            int counter1 = 0;
            counter = 1;
            while (!st1.empty() && st1.back() < heights[i]) {
                st2.push_back(st1.back());
                st1.pop_back();
                counter1++;
            }
            act.push_back(2);
            act.push_back(counter1);
            st1.push_back(heights[i]);
        }
        if (!st2.empty() && st2.back() > heights[i]) {
            cout << 0;
            return 0;
        }
    }
    if (counter > 0) {
        act.push_back(1);
        act.push_back(counter);
    }
    act.push_back(2);
    act.push_back(st1.size());
    cout << act.size() / 2 << endl;
    for (int i = 0; i < act.size(); i += 2)
        cout << act[i] << " " << act[i + 1] << endl;
    return 0;
}
