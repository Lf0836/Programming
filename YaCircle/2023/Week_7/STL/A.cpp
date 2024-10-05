#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> Min(const vector<int>& lenta, int win) {
  vector<int> mins;
  deque<int> deque;
  for (int i = 0; i < lenta.size(); i++) {
    if (!deque.empty() && deque.front() <= i - win) {
      deque.pop_front();
    }
    while (!deque.empty() && lenta[deque.back()] >= lenta[i]) {
      deque.pop_back();
    }
    deque.push_back(i);
    if (i >= win - 1) {
      mins.push_back(lenta[deque.front()]);
    }
  }
  return mins;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> lenta(n);
  for (int i = 0; i < n; i++) {
    cin >> lenta[i];
  }
  vector<int> mins = Min(lenta, k);
  for (int i = 0; i < mins.size(); i++) {
    cout << mins[i] << ' ';
  }
  return 0;
}
