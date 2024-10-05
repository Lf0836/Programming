#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Apple {
    int x, y, z, r;
};

bool doApplesIntersect(const Apple& a, const Apple& b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    int dist = dx * dx + dy * dy;
    int sumrad = (a.r + b.r) * (a.r + b.r);
    if (a.z >= b.z) return false;
    return dist <= sumrad;
}

set<int> findFallenApples(const vector<Apple>& apples) {
    int n = apples.size();
    set<int> fallen;
    fallen.insert(1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (fallen.count(j + 1) && doApplesIntersect(apples[i], apples[j])) {
                fallen.insert(i + 1);
                break;
            }
        }
    }
    return fallen;
}

int main() {
    int n;
    cin >> n;
    vector<Apple> apples(n);
    for (int i = 0; i < n; ++i) {
        cin >> apples[i].x >> apples[i].y >> apples[i].z >> apples[i].r;
    }
    set<int> fallenApples = findFallenApples(apples);
    cout << fallenApples.size() << endl;
    for (int i : fallenApples) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}