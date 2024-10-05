#include <iostream>
#include <cmath>

using namespace std;

struct P {
    double x, y;
};

double dist(P p1, P p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    P CRY;
    double rad;
    P p;

    cin >> CRY.x >> CRY.y >> rad >> p.x >> p.y;

    double d = dist(CRY, p);

    if (d < rad) {
        cout << "0" << endl;
    } else if (fabs(d - rad) < 1e-6) {
        cout << "1" << endl;
        cout << p.x << " " << p.y << endl;
    } else {
        double angle = acos(rad / d);
        double angle_CRY = atan2(p.y - CRY.y, p.x - CRY.x);
        double angle_1 = angle_CRY + angle;
        double angle_2 = angle_CRY - angle;
        P p_1 = {CRY.x + rad * cos(angle_1), CRY.y + rad * sin(angle_1)};
        P p_2 = {CRY.x + rad * cos(angle_2), CRY.y + rad * sin(angle_2)};
        cout << "2" << endl;
        cout.precision(10);
        cout << fixed << p_1.x << " " << p_1.y << endl;
        cout << fixed << p_2.x << " " << p_2.y << endl;
    }
    return 0;
}
