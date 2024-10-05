#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> seque(40);
    seque[1] = 2;
    seque[2] = 4;
    seque[3] = 7;
    int id = 4;
    while (id <= n) {
        seque[id] = seque[id-1] + seque[id-2] + seque[id-3];
        id++;
    }
    cout << seque[n] << endl;
    return 0;
}
