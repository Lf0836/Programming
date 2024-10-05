#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int FST(int numV, int SV, int TV, const vector<vector<pair<int, pair<int, int>>>>& busSchedule) {
    const int INF = numeric_limits<int>::max();
    vector<int> time(numV + 1, INF);
    time[SV] = 0;
    vector<bool> visited(numV + 1, false);

    while (true) {
        int minTime = INF;
        int minVillage = -1;
        for (int i = 1; i <= numV; i++) {
            if (!visited[i] && time[i] < minTime) {
                minTime = time[i];
                minVillage = i;
            }
        }
        if (minTime == INF) {
            break;
        }
        int currentVillage = minVillage;
        visited[currentVillage] = true;

        for (auto bus : busSchedule[currentVillage]) {
            int depTime = bus.first;
            int dest = bus.second.first;
            int arrTime = bus.second.second;
            if (time[currentVillage] <= depTime && arrTime < time[dest]) {
                time[dest] = arrTime;
            }
        }
    }

    if (time[TV] == INF) {
        return -1;
    } else {
        return time[TV];
    }
}

int main() {
    int numV;
    cin >> numV;

    int SV, TV;
    cin >> SV >> TV;

    vector<vector<pair<int, pair<int, int>>>> busSchedule(numV + 1);
    int numBuses;
    cin >> numBuses;
    for (int i = 0; i < numBuses; i++) {
        int start, depTime, dest, arrTime;
        cin >> start >> depTime >> dest >> arrTime;
        busSchedule[start].push_back(make_pair(depTime, make_pair(dest, arrTime)));
    }

    int shortestTime = FST(numV, SV, TV, busSchedule);

    cout << shortestTime << '\n';

    return 0;
}