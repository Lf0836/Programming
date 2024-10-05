#include <iostream>

int main() {
    int n, length;
    std::cin >> n >> length;
    int shipCoords = 0;
    if (n % length == 0) {
        shipCoords = n / length;
    } else {
        shipCoords = n / length + 1;
    }
    std::cout << shipCoords+length-1;
    return 0;
}