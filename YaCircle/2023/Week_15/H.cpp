#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> AdicList;
vector<bool> visted;
vector<int> travlsed;
vector<pair<int, int>> NEdg;

void dfs(int vertex) {
    visted[vertex] = true;
    travlsed.push_back(vertex);
    for (int i = 0; i < AdicList[vertex].size(); i++) {
        if (visted[AdicList[vertex][i].first] != true) {
            NEdg[AdicList[vertex][i].second] = {vertex, AdicList[vertex][i].first};
            dfs(AdicList[vertex][i].first);
        }
    }
    travlsed.push_back(vertex);
}

vector<vector<int>> revAdisList;

void dfsReversed(int vertex) {
    visted[vertex] = true;
    for (int i = 0; i < revAdisList[vertex].size(); i++) {
        if (visted[revAdisList[vertex][i]] != true) {
            dfsReversed(revAdisList[vertex][i]);
        }
    }
}

int main() {
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;
    AdicList = vector<vector<pair<int, int>>>(numVertices + 1);
    visted = vector<bool>(numVertices + 1, false);
    travlsed = vector<int>(0);
    NEdg = vector<pair<int, int>>(numEdges, {-1, -1});
    vector<pair<int, int>> edgeList(numEdges);
    for (int i = 0; i < numEdges; i++) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        edgeList[i] = {vertex1, vertex2};
        AdicList[vertex1].push_back({vertex2, i});
        AdicList[vertex2].push_back({vertex1, i});
    }
    dfs(1);
    vector<pair<int, int>> orderInterval(numVertices + 1, {-1, -1});
    for (int i = 0; i < travlsed.size(); i++) {
        int vertex = travlsed[i];
        if (orderInterval[vertex].first != -1) {
            orderInterval[vertex].second = i;
            continue;
        }
        orderInterval[vertex].first = i;
    }
    for (int i = 0; i < numEdges; i++) {
        if (NEdg[i].first == -1) {
            NEdg[i] = edgeList[i];
            if (orderInterval[edgeList[i].first].first < orderInterval[edgeList[i].second].first) {
                NEdg[i] = {edgeList[i].second, edgeList[i].first};
            }
        }
    }
    revAdisList = vector<vector<int>>(numVertices + 1);
    for (int i = 0; i < numEdges; ++i) {
        revAdisList[NEdg[i].first].push_back(NEdg[i].second);
    }
    for (int j = 2; j <= numVertices; j++) {
        visted = vector<bool>(numVertices + 1, false);
        dfsReversed(j);
        if (visted[1] == false) {
            cout << 0;
            return 0;
        }
    }
    for (int i = 0; i < numEdges; i++) {
        cout << NEdg[i].first << " " << NEdg[i].second << endl;
    }
    return 0;
}
