#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long i = 1;
    long long j = 1;
    int counter = 0;
    long long res = 0;
    while (counter < n) {
        if (i*i < j*j*j) {
            res = i*i;
            i++;
            counter++;
        } else {
            if (i*i > j*j*j) {
                res = j*j*j;
                j++;
                counter++;
            } else {
                res = i*i;
                i++;
                j++;
                counter++;
            }
        }
    }
    cout << res;
    return 0;
}
