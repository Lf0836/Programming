#include <iostream>

using namespace std;

int counter = 0;

int fibana(int n) {
    ++counter;
    if (n < 3) {
        return 1;
    }
    return fibana(n - 1) + fibana(n - 2);
}

int main() {
    int n;
    cin >> n;
    fibana(n);
    cout << counter;
}
