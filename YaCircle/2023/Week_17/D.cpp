#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    long n;
    cin >> n;
    for (long i = 0; i < n; i++) {
        long num;
        cin >> num;
        long count = 0;
        for (long j = 31; j >= 0; j--) {
            if ((num >> j) & 1) {
                count++;
            }
        }
        cout << long(pow(2, count)) << endl;
    }
    return 0;
}
