#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
            if ((m[i][j] == 0) && (i != j))
                m[i][j] = INF;
        }
    }
    floid();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] == INF) {
                res[i][j] = 0;
            } else {
                res[i][j] = 1;
                for (int k = 0; k < n; k++) {
                    if ((m[k][k] < 0) && (m[i][k] < INF) && (m[k][j] < INF))
                        res[i][k] = res[i][j] = res[k][j] = 2;
                }
            }
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
