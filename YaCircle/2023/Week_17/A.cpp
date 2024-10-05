#include <iostream>
#include <bitset>

using namespace std;

int main() {
    int n;
    cin >> n;
    bitset<8> binNum(n);
    cout << binNum;
    return 0;
}
