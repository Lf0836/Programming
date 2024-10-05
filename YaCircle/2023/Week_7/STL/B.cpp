#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    string find_val;
    map<string, string> m;
    for (int i = 0; i < n; i++) {
        string sin1, sin2;
        cin >> sin1 >> sin2;
        m[sin1] = sin2;
        m[sin2] = sin1;
    }
    cin >> find_val;
    cout << m[find_val];
    return 0;
}
