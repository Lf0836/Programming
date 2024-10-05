#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int, int>> lunarJumps(int n, int m, vector<int>& strengths, vector<vector<int>>& moves) {
    vector<pair<int, int>> results;
    vector<int> jumps(n, 0);
    vector<int> lastLunar(n, 0);
    for (int i = 0; i < m; i++) {
        if (moves[i][0] == 1) {
            int currentLunar = moves[i][1] - 1;
            int jumpsCount = 0;
            while (currentLunar < n && currentLunar >= 0) {
                jumpsCount++;
                lastLunar[currentLunar] = currentLunar + strengths[currentLunar];
                currentLunar = lastLunar[currentLunar];
            }
            results.push_back({currentLunar + 1, jumpsCount});
        } else {
            int lunarIndex = moves[i][1] - 1;
            strengths[lunarIndex] = moves[i][2];
        }
    }
    return results;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> strengths(n);
    for (int i = 0; i < n; i++) {
        cin >> strengths[i];
    }
    vector<vector<int>> moves(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> moves[i][j];
        }
    }
    vector<pair<int, int>> results = lunarJumps(n, m, strengths, moves);
    for (auto res : results) {
        cout << res.first << " " << res.second << endl;
    }
    return 0;
}
