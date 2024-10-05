#include <iostream>
#define INF 30000

using namespace std;

int main() {
    long n, m, i, j, k;
    bool f;
    cin >> n >> m;
    long r[m][3], d[n];
    for (i = 0; i < n; ++i)
        d[i] = INF;
    d[0] = 0;
    for (i = 0; i < m; ++i) {
        cin >> r[i][0] >> r[i][1] >> r[i][2];
        r[i][0]--;
        r[i][1]--;
    }
    do {
        f = false;
        for (k = 0; k < m; ++k) {
            i = r[k][0];
            j = r[k][1];
            if (d[i] < INF && d[j] > d[i] + r[k][2]) {
                f = true;
                d[j] = d[i] + r[k][2];
            }
        }
    } while (f);
    for (auto e : d)
        cout << e << ' ';
    cout << endl;
    return 0;
}