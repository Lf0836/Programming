#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
void SimFract(int& num, int& denom) {
    int ComDiv = gcd(num, denom);
    num /= ComDiv;
    denom /= ComDiv;
}
void AddFract(int numer1, int denom1, int numer2, int denom2, int& numerSum, int& denomSum) {
    denomSum = denom1 * denom2;
    numerSum = numer1 * denom2 + numer2 * denom1;
}
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int numSum, denomSum;
    AddFract(a, b, c, d, numSum, denomSum);
    SimFract(numSum, denomSum);
    cout << numSum << " " << denomSum;
    return 0;
}
