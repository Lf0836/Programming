#include <iostream>
#include <vector>

using namespace std;

void printSub(const vector<char>& sub) {
    for (char ch : sub) {
        cout << ch;
    }
    cout << endl;
}

void genSub(int n, vector<char>& sub, int index = 0) {
    if (index == n) {
        if (!sub.empty()) {
            printSub(sub);
        }
        return;
    }
    genSub(n, sub, index + 1);
    sub.push_back('a' + index);
    genSub(n, sub, index + 1);
    sub.pop_back();
}

int main() {
    int n;
    cin >> n;
    vector<char> sub;
    genSub(n, sub);
    return 0;
}
