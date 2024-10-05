#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& listA, int vt, vector<bool>& vtd) {
    vtd[vt] = true;
    for (int neighbor : listA[vt]) {
        if (!vtd[neighbor]) {
            dfs(listA, neighbor, vtd);
            cout << vt + 1 << " " << neighbor + 1 << endl;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> listA(n);
    for (int i = 0; i < m; ++i) {
        int source, destination;
        cin >> source >> destination;
        --source, --destination;
        listA[source].push_back(destination);
        listA[destination].push_back(source);
    }
    vector<bool> vtd(n, false);
    dfs(listA, 0, vtd);
    return 0;
}
