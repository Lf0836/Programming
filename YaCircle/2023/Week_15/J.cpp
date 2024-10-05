#include <iostream>
#include <vector>

using namespace std;

bool k;
vector<vector<int>> a;
vector<int> c;
vector<bool> used;

int g, h;

void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < a[v].size(); i++) {
        int u = a[v][i];
        if (c[u] == c[v]) {
            k = false;
        }
        if (used[u] == true) {
            continue;
        }
        int y = c[v] + 1;
        if (y % 2 == 0) {
            c[u] = 2;
            h++;
        }
        if (y % 2 == 1) {
            c[u] = 1;
            g++;
        }
        dfs(u);
    }
}
int main() {
    int n;
    cin >> n;
    a = vector<vector<int>>(n + 1);
    used = vector<bool>(n + 1, false);
    c = vector<int>(n + 1);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        if (c[i] == 1) {
            res++;
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        a[v].push_back(u);
        a[u].push_back(v);
    }
    int y = 0, u = 0, l = 0;
    for (int i = 1; i <= n; i++) {
        if (used[i] == false && c[i] == 1) {
            if (a[i].size() == 0) {
                continue;
            }
            g = 1, h = 0;
            k = true;
            dfs(i);
            if (k == false) {
                l += (g + h);
                continue;
            }
            y += g;
            u += h;
        }
    }
    cout << max(res, l + max(y, u));
    return 0;
}
