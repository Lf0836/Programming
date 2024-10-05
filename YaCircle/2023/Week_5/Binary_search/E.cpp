#include<iostream>

using namespace std;

int A, B, C, D;

double func(double x) {
    return A * x * x * x + B * x * x + C * x + D;
}

int main() {
    cin >> A >> B >> C >> D;
    double r = 1;
    while (func(r)*func(-r) >= 0) {
        r *= 2;
    }
    double l = -r;
    while (r - l > 1e-6) {
        double mid = (r + l) / 2;
        if (func(mid)*func(r) > 0) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << l << endl;
    return 0;
}
