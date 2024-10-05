#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 105;
vector<int> adj[MAXN];
int weight[MAXN];
int dp[MAXN][2];

void dfs(int u, int parent) {
    dp[u][0] = 0;
    dp[u][1] = weight[u];
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int parent, w;
        cin >> parent >> w;
        weight[i] = w;
        adj[parent].push_back(i);
    }
    dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]) << endl;
    return 0;
}
