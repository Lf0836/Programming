#include <iostream>
#include <map>
#include <set>

using namespace std;

struct SetManager {
  map<unsigned long long, set<unsigned long long>> sets;
  map<unsigned long long, set<unsigned long long>> elements;
  void add(unsigned long long e, unsigned long long s) {
    sets[s].insert(e);
    elements[e].insert(s);
  }
  void del(unsigned long long e, unsigned long long s) {
    sets[s].erase(e);
    elements[e].erase(s);
  }
  void clear(unsigned long long s) {
    for (auto e : sets[s]) {
      elements[e].erase(s);
    }
    sets[s].clear();
  }
  void listSet(unsigned long long s) {
    if (sets[s].empty()) {
      cout << -1 << " ";
    } else {
      for (auto e : sets[s]) {
        cout << e << " ";
      }
    }
    cout << endl;
  }
  void listSetsOf(unsigned long long e) {
    if (elements[e].empty()) {
      cout << -1 << " ";
    } else {
      for (auto s : elements[e]) {
        cout << s << " ";
      }
    }
    cout << endl;
  }
};

int main() {
  unsigned long long n, m, k;
  cin >> n >> m >> k;
  SetManager manager;
  for (int i = 0; i < k; ++i) {
    string operation;
    cin >> operation;
    if (operation == "ADD") {
      unsigned long long e, s;
      cin >> e >> s;
      manager.add(e, s);
    } else if (operation == "DELETE") {
      unsigned long long e, s;
      cin >> e >> s;
      manager.del(e, s);
    } else if (operation == "CLEAR") {
      unsigned long long s;
      cin >> s;
      manager.clear(s);
    } else if (operation == "LISTSET") {
      unsigned long long s;
      cin >> s;
      manager.listSet(s);
    } else if (operation == "LISTSETSOF") {
      unsigned long long e;
      cin >> e;
      manager.listSetsOf(e);
    }
  }
  return 0;
}
