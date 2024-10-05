#include <iostream>
#include <deque>
#include <cstring>

#define MAX 10000

std::deque<int> d;
int used[MAX], prev[MAX];

int AddOne(int n) {
    if (n / 1000 != 9)
        return n + 1000;
    return n;
}

int MinusOne(int n) {
    if (n % 10 != 1)
        return n - 1;
    return n;
}

int ShiftLeft(int n) {
    return (n % 1000) * 10 + n / 1000;
}

int ShiftRight(int n) {
    return (n % 10) * 1000 + n / 10;
}

void path(int n) {
    if (n == -1)
        return;
    path(prev[n]);
    std::cout << n << std::endl;
}

void bfs(int start, int target) {
    int v, u, i;
    int (*Op[4])(int) = {AddOne, MinusOne, ShiftLeft, ShiftRight};

    d.push_front(start);
    used[start] = 1;

    while (!d.empty()) {
        u = d.front();
        d.pop_front();

        if (u == target)
            break;

        for (i = 0; i < 4; i++) {
            v = Op[i](u);
            if (!used[v]) {
                used[v] = 1;
                prev[v] = u;
                d.push_back(v);
            }
        }
    }
}

int main() {
    int start, target;
    std::cin >> start >> target;
    std::memset(used, 0, sizeof(used));
    std::memset(prev, -1, sizeof(prev));
    bfs(start, target);
    path(target);
    return 0;
}