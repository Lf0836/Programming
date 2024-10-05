#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> getEvents(long long n, long long k, vector<long long>& a) {
    vector<vector<long long>> events(k);
    for (long long i = 0; i < k; i++) {
        long long e, v;
        cin >> e >> v;
        events[i] = {e, v};
    }
    return events;
}

long long getSumOfSquares(vector<long long>& a) {
    long long sum = 0;
    for (long long num : a) {
        sum += num * num;
    }
    return sum;
}

long long getSumOfSquaresAfterEvents(long long n, vector<vector<long long>>& events, vector<long long>& a) {
    long long sum = getSumOfSquares(a);
    for (vector<long long>& event : events) {
        long long e = event[0], v = event[1];
        if (e == 1) {
            long long left = v - 1, right = v + 1;
            if (right < n) {
                a[v] += a[right];
                if (a[right] % 2 == 0) {
                    a[right] = a[v];
                } else {
                    a[right] = a[v] - (a[right] - a[v]);
                }
                a[left] += a[right];
            } else {
                a[v] += a[left];
                if (a[left] % 2 == 0) {
                    a[left] = a[v];
                } else {
                    a[left] = a[left] - (a[v] - a[left]);
                }
            }
        } else if (e == 2) {
            long long left = v - 1, right = v + 1;
            if (right < n) {
                a[v] = (a[v] + a[right]) / 2;
                a[right] = a[v];
                a[left] = (a[left] + a[right]) / 2;
            } else {
                a[v] = (a[v] + a[left]) / 2;
                a[left] = a[v];
            }
        }
        sum += getSumOfSquares(a);
    }
    return sum;
}

int main() {
    long long n, p, k;
    cin >> n >> p >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<long long>> events = getEvents(n, k, a);
    cout << getSumOfSquaresAfterEvents(n, events, a) << endl;
    return 0;
}
