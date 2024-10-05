#include <iostream>
#include <stdio.h>
#include <climits>

using namespace std;

int main() {
    srand(23120309);
    int nSt, nP, nQ;
    scanf("%d %d %d", &nSt, &nP, &nQ);
    static int big_num[199999];
    for (int i = 0; i < nSt; ++i) {
        big_num[i] = nP;
    }
    for (int q = 0; q < nQ; ++q) {
        int left, right;
        scanf("%d %d", &left, &right);
        int mid = left + rand() % (right - left);
        for (int i = mid; i < right; ++i) {
            if (big_num[i] == 0) {
                cout << '0' << endl;
                goto BREAK;
            }
        }
        for (int i = left; i < mid; ++i) {
            if (big_num[i] == 0) {
                cout << '0' << endl;
                goto BREAK;
            }
        }
        printf("1\n");
        for (int i = left; i < right; ++i) {
            big_num[i]--;
        }
        BREAK: {}
    }
}
