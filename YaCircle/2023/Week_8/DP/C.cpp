#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> res(n);
    vector<int> pr(n);
    for (int i = 0; i < n; ++i)
        cin >> pr[i];
    res[0] = pr[0];
    res[1] = pr[1];
    for (int i = 2; i < n; ++i)
        res[i] = min(res[i-1], res[i-2]) + pr[i];
    cout << res[n-1] << endl;
    return 0;
}
