#include <bits/stdc++.h>

using namespace std;

struct Wood {
  int x;
  int t;
};
bool comp_W(const Wood &a, const Wood &b) { return a.t < b.t; }
void reader(vector<Wood> &Woods) {
  int n;
  cin >> n;
  Woods.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> Woods[i].x >> Woods[i].t;
  }
}
void sorter(vector<Wood> &Woods) { sort(Woods.begin(), Woods.end(), comp_W); }
void grouper_t(const vector<Wood> &Woods, map<int, vector<int>> &byTime) {
  for (const auto &Wood : Woods) {
    byTime[Wood.t].push_back(Wood.x);
  }
}
void calc_dp(const map<int, vector<int>> &byTime, long long &dpL,
             long long &dpR, int &prevMin, int &prevMax) {
  for (const auto &pair : byTime) {
    vector<int> pos = pair.second;
    sort(pos.begin(), pos.end());
    int curMin = pos[0];
    int curMax = pos[pos.size() - 1];
    long long nextDpL =
        min(dpL + abs(curMax - prevMin), dpR + abs(curMax - prevMax)) +
        (curMax - curMin);
    long long nextDpR =
        min(dpL + abs(curMin - prevMin), dpR + abs(curMin - prevMax)) +
        (curMax - curMin);
    dpL = nextDpL;
    dpR = nextDpR;
    prevMin = curMin;
    prevMax = curMax;
  }
}
void couter(long long dpL, long long dpR, int prevMin, int prevMax) {
  cout << min(dpL + abs(prevMin), dpR + abs(prevMax)) << endl;
}
int main() {
  vector<Wood> Woods;
  reader(Woods);
  sorter(Woods);
  map<int, vector<int>> byTime;
  grouper_t(Woods, byTime);
  long long dpL = 0, dpR = 0;
  int prevMin = 0, prevMax = 0;
  calc_dp(byTime, dpL, dpR, prevMin, prevMax);
  couter(dpL, dpR, prevMin, prevMax);
  return 0;
}
