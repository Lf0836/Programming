#include <iostream>
#include <vector>

using namespace std;

void printStr(const vector<int>& currStr) {
    for (int num : currStr) {
        cout << num;
    }
    cout << endl;
}

void genStr(int n, int k, vector<int>& currStr) {
    if (n == 0) {
        printStr(currStr);
        return;
    }
    for (int num = 0; num < k; num++) {
        currStr.push_back(num);
        genStr(n - 1, k, currStr);
        currStr.pop_back();
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> currStr;
    genStr(N, K, currStr);
    return 0;
}