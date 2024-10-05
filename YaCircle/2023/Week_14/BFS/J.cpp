#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector <vector<int>> g;
vector<int> d;
vector<int> p;
vector<int> st;

void bfs() {
    queue<int> q;
    for (auto el : st) {
        q.push(el);
        d[el] = 0;
        p[el] = el;
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
            if (d[u] == -1) {
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = p[v];
            }
        }
    }
}
int main() {
    int n, elmOne, elmTwo, k, m;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> elmOne;
        st.push_back(elmOne-1);
    }
    sort(st.begin(), st.end());
    cin >> m;
    g.resize(n);
    d.resize(n, -1);
    p.resize(n, -1);
    for (int i = 0; i < m; i++) {
        cin >> elmOne  >> elmTwo;
        g[elmOne-1].push_back(elmTwo-1);
        g[elmTwo-1].push_back(elmOne-1);
    }
    bfs();
    for (auto e : d) {
        cout << e << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << p[i] + 1 << " ";
    }
    return 0;
}
