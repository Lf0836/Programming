#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double eps = 1e-6;

double func(double x) {
    return x * x + sqrt(x);
}

int main() {
    double n;
    cin >> n;
    double l = 0, r = n;
    for (int it = 0; it <= 250; it++) {
        double mid = (l + r) / 2;
        if (func(mid) > n)
            r = mid;
        else
            l = mid;
    }
    cout << fixed << setprecision(9) << l;
    return 0;
}