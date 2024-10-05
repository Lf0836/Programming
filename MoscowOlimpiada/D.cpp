#include <iostream>
#include <unordered_map>

using namespace std;

long countPairs(long n, long* a) {
  unordered_map<long, long> freq;
  long count = 0;
  for (long i = 0; i < n; i++) {
    count += freq[a[i] - i];
    freq[a[i] - i]++;
  }
  return count;
}

int main() {
  long n;
  cin >> n;
  long* a = new long[n];
  for (long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long result = countPairs(n, a);
  cout << result << endl;
  delete[] a;
  return 0;
}
