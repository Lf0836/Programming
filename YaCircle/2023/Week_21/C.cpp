#include <iostream>
#include <vector>

using namespace std;

vector <int> heap;
int miner = 0;
int Shift(int i) {
    while (2 * i + 1 < miner) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int j = l;
        if (r < miner && heap[r] > heap[l]) {
            j = r;
        }
        if (heap[i] >= heap[j]) {
            break;
        }
        swap(heap[i], heap[j]);
        i = j;
    }
    return i;
}
int ex_max() {
    int s = miner;
    int max = heap[0];
    heap[0] = heap[miner - 1];
    miner--;
    cout << Shift(0) + 1 << " ";
    return max;
}

int main() {
    int n, elm, m, id, x;
    cin >> n;
    miner = n;
    for (int i = 0; i < n; i++) {
        cin >> elm;
        heap.push_back(elm);
    }
    for (int i = 0; i < n-1; i++) {
        cout << ex_max() << endl;
    }
    return 0;
}
