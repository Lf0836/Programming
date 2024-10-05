#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool posFit(int dist, int k, const vector<int>& st) {
  int count = 1;
  int niceS = st[0];
  for (int i = 1; i < st.size(); i++) {
    if (st[i] - niceS >= dist) {
      count++;
      if (count == k) return true;
      niceS = st[i];
    }
  }
  return false;
}

int Mdist(int n, int k, const vector<int>& st) {
  int l = 1;
  int r = st[n - 1] - st[0];
  int Mdist = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (posFit(mid, k, st)) {
      Mdist = max(Mdist, mid);
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return Mdist;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> st(n);
  for (int i = 0; i < n; i++) {
    cin >> st[i];
  }
  cout << Mdist(n, k, st) << endl;
  return 0;
}
