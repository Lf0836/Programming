#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
#define INF INT_MAX

using namespace std;

void findMinCost(int qCities, int qFlights, int maxN, int sTown, int fTown, const vector<tuple<int, int, int>> &allFlights) {
    vector<vector<int>> dist(maxN + 1);
    for (int night = 0; night < maxN + 1; ++night) {
        for (int town = 0; town < qCities; ++town) {
            if (night == 0 && town == sTown - 1) {
                dist[night].push_back(0);
            } else {
                dist[night].push_back(INF);
            }
        }
    }

    for (;;) {
        bool wasRelaxed = false;
        for (int night = 1; night < maxN + 1; ++night) {
            for (auto &flight : allFlights) {
                int u, v, w;
                tie(u, v, w) = flight;
                if (dist[night - 1][u] != INF) {
                    if (dist[night][v] > dist[night - 1][u] + w) {
                        dist[night][v] = dist[night - 1][u] + w;
                        wasRelaxed = true;
                    }
                }
            }
        }
        if (!wasRelaxed) {
            break;
        }
    }

    int minCost = INF;
    for (int night = 0; night <= maxN; night++) {
        if (dist[night][fTown - 1] < minCost) {
            minCost = dist[night][fTown - 1];
        }
    }

    if (minCost == INF) {
        cout << -1;
    } else {
        cout << minCost;
    }
    cout << endl;
}

int main() {
    int qCities, qFlights, maxN, sTown, fTown;
    cin >> qCities >> qFlights >> maxN >> sTown >> fTown;
    vector<tuple<int, int, int>> allFlights;
    for (int i = 0; i < qFlights; ++i) {
        int first, second, cost;
        cin >> first >> second >> cost;
        allFlights.emplace_back(first - 1, second - 1, cost);
    }
    findMinCost(qCities, qFlights, maxN, sTown, fTown, allFlights);
    return 0;
}
