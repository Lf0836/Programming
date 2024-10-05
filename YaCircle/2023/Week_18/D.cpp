#include <iostream>
#include <vector>

using namespace std;

const long long INF_ = 1e9;
long double threshold = 1e-9;
vector<long long> valls_hash, powb, sub_valls_hash, pow_subb;
long long  base = 27;
long long mod_value = 1e9 + 7;
long long compute_hash(long long l, long long r) {
    return (valls_hash[r + 1] - (valls_hash[l] * powb[r - l + 1]) % mod_value + mod_value) % mod_value;
}
long long compute_hash_sub(long long l, long long r) {
    return (sub_valls_hash[r + 1] - (sub_valls_hash[l] * pow_subb[r - l + 1]) % mod_value + mod_value) % mod_value;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string main_str, sub_str;
    cin >> sub_str;
    long long len_str = sub_str.size();
    valls_hash.resize(len_str + 1);
    powb.resize(len_str + 1);
    long long length, index;
    valls_hash[0] = 0;
    powb[0] = 1;
    for (index = 0; index < len_str; index++) {
        valls_hash[index + 1] = (valls_hash[index] * base + (sub_str[index] - 'a' + 1)) % mod_value;
        powb[index + 1] = (powb[index] * base) % mod_value;
    }
    sub_valls_hash.resize(len_str + 1);
    pow_subb.resize(len_str + 1);
    sub_valls_hash[0] = 0;
    pow_subb[0] = 1;
    for (index = 1; index <= sub_str.size(); index++) {
        main_str += sub_str[index - 1];
        sub_valls_hash[index] = (sub_valls_hash[index - 1] * base + (main_str[index - 1] - 'a' + 1)) % mod_value;
        pow_subb[index] = (pow_subb[index - 1] * base) % mod_value;
        long long matching_count = 0;
        long long sub_str_len = main_str.size();
        for (long long i = 0; i <= len_str - sub_str_len; i += index) {
            if (compute_hash(i, i + sub_str_len - 1) == compute_hash_sub(0, sub_str_len - 1)) {
                matching_count++;
            }
        }
        if (len_str % index == 0 && sub_str.size() / index == matching_count) {
            cout << sub_str.size() / index;
            return 0;
        }
    }
}
