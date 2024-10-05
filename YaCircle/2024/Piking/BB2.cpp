#include <bits/stdc++.h>

using namespace std;

const int One_e_nine = 1e9;

vector<pair<int, int>> ans;
vector<bool> checked;
vector<int> seq;

void ex(int node) {
  checked[node] = true;
  if (!checked[ans[node].first]) ex(ans[node].first);
  seq.push_back(node);
  if (!checked[ans[node].second]) ex(ans[node].second);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  ans.resize(n + 1);
  checked.resize(n + 1);
  vector<int> seq_F(n), seq_S(n);
  for (int id = 0; id < n; ++id) {
    cin >> seq_F[id];
  }
  for (int id = 0; id < n; ++id) {
    cin >> seq_S[id];
  }
  if (seq_F[0] != 1) {
    cout << -1;
    return 0;
  }
  int cur = 0, secid = 0, firid = 0;
  while (firid < n) {
    checked[seq_F[firid]] = true;
    ans[cur].second = seq_F[firid];
    cur = seq_F[firid];
    while (seq_F[firid] != seq_S[secid]) {
      ++firid;
      checked[seq_F[firid]] = true;
      ans[cur].first = seq_F[firid];
      cur = seq_F[firid];
    }
    ++firid;
    ++secid;
    while (firid < n && checked[seq_S[secid]]) {
      cur = seq_S[secid];
      ++secid;
    }
  }
  checked.assign(n, false);
  checked[0] = true;
  ex(1);
  for (int id = 0; id < n; ++id) {
    if (seq_S[id] != seq[id]) {
      cout << -1;
      return 0;
    }
  }
  for (int id = 1; id <= n; ++id) {
    cout << ans[id].first << " " << ans[id].second << endl;
  }
  return 0;
}
