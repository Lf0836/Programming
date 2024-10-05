#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isDivisibleBySquare(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % (i * i) == 0) {
            return true;
        }
    }
    return false;
}

bool hasGCDofOne(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return (a == 1);
}

int main() {
    int start, end;
    cin >> start >> end;

    vector<int> numbers;

    for (int i = start; i <= end; i++) {
        if (!isDivisibleBySquare(i)) {
            numbers.push_back(i);
        }
    }

    int count = 0;
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            if (hasGCDofOne(numbers[i], numbers[j])) {
                count++;
            }
        }
    }

    cout << count;

    return 0;
}
