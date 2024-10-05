#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

const int MAX_NODES = 1000001;

vector<vector<int>> adjacency_list(MAX_NODES);
vector<vector<int>> reversed_adjacency_list(MAX_NODES);
vector<bool> visited(MAX_NODES);
stack<int> order;
vector<int> component(MAX_NODES * 2);

void initialize(int n) {
    for (int i = 0; i <= 2 * n; i++) {
        adjacency_list[i].clear();
        reversed_adjacency_list[i].clear();
        visited[i] = false;
        component[i] = -1;
    }
}
void dfs1(int node) {
    visited[node] = true;
    for (int neighbor : adjacency_list[node]) {
        if (!visited[neighbor]) {
            dfs1(neighbor);
        }
    }
    order.push(node);
}
void dfs(int node, int comp) {
    component[node] = comp;
    for (int neighbor : reversed_adjacency_list[node]) {
        if (component[neighbor] == -1) {
            dfs(neighbor, comp);
        }
    }
}
void FSCC(int n) {
    for (int i = 0; i < 2 * n; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    int comp_number = 0;
    while (!order.empty()) {
        int node = order.top();
        order.pop();
        if (component[node] == -1) {
            dfs(node, comp_number++);
        }
    }
}
void AdEd(int u, int e1, int v, int e2) {
    u = 2 * u + e1;
    v = 2 * v + e2;
    adjacency_list[u ^ 1].push_back(v);
    adjacency_list[v ^ 1].push_back(u);
    reversed_adjacency_list[v].push_back(u ^ 1);
    reversed_adjacency_list[u].push_back(v ^ 1);
}
bool ISatisf(int n) {
    for (int i = 0; i < 2 * n; i += 2) {
        if (component[i] == component[i + 1]) {
            return false;
        }
    }
    return true;
}
void printer(int n) {
    for (int i = 0; i < n; i++) {
        cout << (component[2 * i] < component[2 * i + 1]);
    }
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    while (cin >> n >> m) {
        initialize(n);
        for (int i = 0; i < m; i++) {
            int u, e1, v, e2;
            cin >> u >> e1 >> v >> e2;
            AdEd(u, e1, v, e2);
        }
        FSCC(n);
        if (ISatisf(n)) {
            printer(n);
        } else {
            cout << "NO" << endl;
        }
    }
}
