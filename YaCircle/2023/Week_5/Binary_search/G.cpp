#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int numOfElem, FNum, SNum;
    cin >> numOfElem >> FNum >> SNum;
    int l = 0;
    int r = max(FNum, SNum) * (numOfElem - 1);
    int mTime = -1;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if ((mid / FNum) + (mid / SNum) < numOfElem - 1) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << r + min(FNum, SNum);
    return 0;
}
