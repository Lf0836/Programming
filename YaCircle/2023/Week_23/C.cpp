#include <iostream>
#include <cmath>

struct Point {
    int x;
    int y;
};

double calculateAngle(Point A, Point O, Point B) {
    double OA = sqrt(pow(O.x - A.x, 2) + pow(O.y - A.y, 2));
    double OB = sqrt(pow(O.x - B.x, 2) + pow(O.y - B.y, 2));
    double AB = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
    double angle = acos((pow(OA, 2) + pow(OB, 2) - pow(AB, 2)) / (2 * OA * OB));
    return angle;
}

bool isPointInAngle(Point A, Point O, Point B, Point P) {
    double angle_AOP = calculateAngle(A, O, P);
    double angle_BOP = calculateAngle(B, O, P);
    double angle_AOB = calculateAngle(A, O, B);
    if (angle_AOP + angle_BOP <= angle_AOB + 1e-9) {
        return true;
    } else {
        return false;
    }
}

int main() {
    Point A, O, B, P;
    std::cin >> A.x >> A.y;
    std::cin >> O.x >> O.y;
    std::cin >> B.x >> B.y;
    std::cin >> P.x >> P.y;

    if (isPointInAngle(A, O, B, P)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
