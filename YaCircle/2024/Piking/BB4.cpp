#include <bits/stdc++.h>

using namespace std;

struct SeqInf {
  int id;
  int bal;
  int min_bal;
};

SeqInf anal_of_seq(const string& seq, int id) {
  int bal = 0;
  int min_bal = 0;
  for (const auto& c : seq) {
    if (c == '(') {
      bal++;
    } else {
      bal--;
    }
    min_bal = min(min_bal, bal);
  }
  return {id, bal, min_bal};
}

pair<vector<SeqInf>, vector<SeqInf>> reader(int n) {
  vector<SeqInf> post, neg;
  for (int i = 0; i < n; ++i) {
    string seq;
    cin >> seq;
    SeqInf info = anal_of_seq(seq, i + 1);
    if (info.bal >= 0) {
      post.push_back(info);
    } else {
      neg.push_back(info);
    }
  }
  return {post, neg};
}

void sorter(vector<SeqInf>& post, vector<SeqInf>& neg) {
  sort(post.begin(), post.end(),
       [](const SeqInf& a, const SeqInf& b) { return a.min_bal > b.min_bal; });
  sort(neg.begin(), neg.end(), [](const SeqInf& a, const SeqInf& b) {
    return a.bal - a.min_bal > b.bal - b.min_bal;
  });
}

vector<int> comb(const vector<SeqInf>& post, const vector<SeqInf>& neg) {
  int cur_bal = 0;
  vector<int> ans;
  for (const auto& info : post) {
    if (cur_bal + info.min_bal < 0) {
      return {};
    }
    cur_bal += info.bal;
    ans.push_back(info.id);
  }
  for (const auto& info : neg) {
    if (cur_bal + info.min_bal < 0) {
      return {};
    }
    cur_bal += info.bal;
    ans.push_back(info.id);
  }
  if (cur_bal != 0) {
    return {};
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  auto [post, neg] = reader(n);
  sorter(post, neg);
  auto ans = comb(post, neg);
  if (ans.empty()) {
    cout << -1 << endl;
  } else {
    for (const auto& id : ans) {
      cout << id << " ";
    }
    cout << endl;
  }
  return 0;
}
