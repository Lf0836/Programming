#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Class {
    int start;
    int end;
};

int main() {
    vector<Class> Classs;
    int n;
    cin >> n;
    Class input;
    int i = 0;
    while (i < n) {
        cin >> input.start >> input.end;
        Classs.push_back(input);
        i++;
    }
    sort(Classs.begin(), Classs.end(), [](const Class& l1, const Class& l2) {
        return l1.end < l2.end;
    });
    int count = 1;
    Class current = Classs.front();
    auto it = Classs.begin() + 1;
    while (it != Classs.end()) {
        if (current.end <= it->start) {
            current = *it;
            ++count;
        }
        ++it;
    }
    cout << count;
    return 0;
}
