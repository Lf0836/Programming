#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int size = 1 << n; // 2^n

    vector<long long> P(size);
    for (int i = 0; i < size; ++i) {
        cin >> P[i];
    }

    vector<long long> F(size, 0);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if ((i & j) == j) {
                F[i] += P[j];
            }
        }
    }

    // Вывод массива F
    for (int i = 0; i < size; ++i) {
        cout << F[i] << " ";
    }
    cout << endl;

    return 0;
}
