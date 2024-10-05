#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, m, k, de, resultius = 0;
  char
      I_solved_this_problem_for_a_very_long_time_I_am_glad_that_I_solved_it_Congratulate_me;
  cin >> n >> m >> k;

  set<long long> M_1, M_2, M_3, M_4;
  vector<long long> M_4v, M_2v, M_3v, M_1v;

  long long i = 0;
  while (i < k) {
    cin >>
        I_solved_this_problem_for_a_very_long_time_I_am_glad_that_I_solved_it_Congratulate_me >>
        de;
    if (I_solved_this_problem_for_a_very_long_time_I_am_glad_that_I_solved_it_Congratulate_me ==
        '-') {
      if (de % 2 == 0) {
        M_1.insert(de);
      } else {
        M_2.insert(de);
      }
    } else {
      if (de % 2 == 0) {
        M_3.insert(de);
      } else {
        M_4.insert(de);
      }
    }
    i++;
  }
  auto it = M_4.begin();
  while (it != M_4.end()) {
    M_4v.push_back(*it);
    ++it;
  }
  it = M_2.begin();
  while (it != M_2.end()) {
    M_2v.push_back(*it);
    ++it;
  }
  it = M_3.begin();
  while (it != M_3.end()) {
    M_3v.push_back(*it);
    ++it;
  }
  it = M_1.begin();
  while (it != M_1.end()) {
    M_1v.push_back(*it);
    ++it;
  }
  i = 0;
  while (i < M_2v.size()) {
    long long d = M_2v[i];
    if (d <= 0) {
      resultius += min(m + d, n);
    } else {
      resultius += min(n - d, m);
    }
    i++;
  }
  i = 0;
  while (i < M_4v.size()) {
    long long d = M_4v[i];
    if (d <= m + 1) {
      resultius += min(d - 1, n);
    } else {
      resultius += min(n - d + m + 1, m);
    }
    i++;
  }
  i = 0;
  while (i < M_3v.size()) {
    long long d = M_3v[i];
    if (d <= m + 1) {
      resultius += min(d - 1, n);
    } else {
      resultius += min(n - d + m + 1, m);
    }
    i++;
  }
  i = 0;
  while (i < M_1v.size()) {
    long long d = M_1v[i];
    if (d <= 0) {
      resultius += min(m + d, n);
    } else {
      resultius += min(n - d, m);
    }
    i++;
  }
  long long per = 0;
  pair<long long, long long> fh, st;
  i = 0;
  while (i < M_4v.size()) {
    auto el = M_4v[i];
    if (el - 1 <= m) {
      st = {1, el - 1};
    } else {
      st = {el - m, m};
    }
    if (el - 1 <= n) {
      fh = {el - 1, 1};
    } else {
      fh = {n, el - n};
    }
    long long dif =
        upper_bound(M_2v.begin(), M_2v.end(), fh.first - fh.second) -
        lower_bound(M_2v.begin(), M_2v.end(), st.first - st.second);
    per += dif;
    i++;
  }
  i = 0;
  while (i < M_3v.size()) {
    auto el = M_3v[i];
    if (el - 1 <= m) {
      st = {1, el - 1};
    } else {
      st = {el - m, m};
    }
    if (el - 1 <= n) {
      fh = {el - 1, 1};
    } else {
      fh = {n, el - n};
    }
    long long dif =
        upper_bound(M_1v.begin(), M_1v.end(), fh.first - fh.second) -
        lower_bound(M_1v.begin(), M_1v.end(), st.first - st.second);
    per += dif;
    i++;
  }
  cout << resultius - per;
  return 0;
}
