#include <iostream>
#include <vector>

using namespace std;

const int p = 31;
const int m = 197197197197;

long long calc_hash_func(vector<long long>& hash, vector<long long>& pow, int l, int r) {
    return (hash[r] - hash[l] + m) % m * pow[hash.size() - l - 1] % m;
}

vector<long long> hash_func(string const& s) {
    int n = s.length();
    vector<long long> hash(n + 1, 0);
    vector<long long> pow(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        pow[i] = (pow[i - 1] * p) % m;
        hash[i] = (hash[i - 1] + (s[i - 1] - 'a' + 1) * pow[i - 1]) % m;
    }
    return hash;
}

int main() {
    string str;
    cin >> str;
    int n = str.size();
    vector<long long> hash = hash_func(str);
    vector<long long> pow(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        pow[i] = (pow[i - 1] * p) % m;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (calc_hash_func(hash, pow, a - 1, b) == calc_hash_func(hash, pow, c - 1, d)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
