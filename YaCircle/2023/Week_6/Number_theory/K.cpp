#include <iostream>
#include <vector>

using namespace std;

long long HOD(long long a, long long b) {
  while (b != 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}

int main() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> cds(n);
  for (int i = 0; i < n; i++) {
    cin >> cds[i].first >> cds[i].second;
  }
  long long count = 0;
  for (long long i = 0; i < n; i++) {
    long long x = abs(cds[(i + 1) % n].first - cds[i].first);
    long long y = abs(cds[(i + 1) % n].second - cds[i].second);
    count += HOD(abs(x), abs(y));
  }
  cout << count << endl;
  return 0;
}
