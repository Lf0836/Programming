#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool prover(string &x, string &y) {
    int counter = 0;
    int n = x.length();
    for (int i = 0; i < n; ++i) {
        counter += x[i] != y[i];
        if (counter > 1) {
            return false;
        }
    }
    return true;
}

int main() {
    string a, b;
    cin >> a >> b;
    int la = a.length();
    int lb = b.length();
    vector <int> exiter;
    for (int i = 0; i < lb - la + 1; i++) {
        string sravn = "";
        for (int j = i; j < i + la; j++) {
            sravn += b[j];
        }
        if (prover(sravn, a)) {
            exiter.push_back(i + 1);
        }
    }
    cout << exiter.size() << endl;
    for (int i = 0; i < exiter.size(); i++) {
        cout << exiter[i] << ' ';
    }
}
