#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int C, P, N;
    cin >> C >> P >> N;

    int time = 0;
    int cookies = 0;
    int production_rate = 1;

    while (cookies < N) {
        int next_time = (N - cookies) / production_rate + ((N - cookies) % production_rate != 0);
        int next_purchase_time = (C - cookies) / production_rate + ((C - cookies) % production_rate != 0);

        if (next_purchase_time + next_time < next_time) {
            time += next_purchase_time;
            cookies += next_purchase_time * production_rate;
            production_rate += P;
        } else {
            time += next_time;
            cookies = N;
        }
    }

    cout << time << endl;

    return 0;
}
