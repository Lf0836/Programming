#include <limits.h>
#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <unordered_set>

using namespace std;

int main() {
  long unsigned int n, k, p, counter = 0;
  cin >> n >> k >> p;
  list<int> entries[n];
  int history[p];
  for (int i = 0; i < p; i++) {
    cin >> history[i];
    entries[--history[i]].push_back(i);
  }
  unordered_set<int> cars;
  priority_queue<pair<int, int>> ids;
  for (int i = 0; i < p; i++) {
    int curr = history[i];
    entries[curr].pop_front();
    if (cars.find(curr) == cars.end()) {
      if (cars.size() >= k) {
        cars.erase(ids.top().second);
        ids.pop();
      }
      counter++;
      cars.insert(curr);
    }
    if (entries[curr].empty()) {
      ids.push({INT_MAX, curr});
    } else {
      ids.push({entries[curr].front(), curr});
    }
  }
  cout << counter << endl;
  return 0;
}
