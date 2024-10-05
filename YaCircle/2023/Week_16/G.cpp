#include <iostream>
#include <cstring>
#define MAX 110
#define INF 0x3F3F3F3F

using namespace std;

int graph[MAX][MAX];
int dist[MAX], predec[MAX];
int cycle[2*MAX], CycLeng;

int FloydWarshall(int n) {
    int i, j, k;
    int temp[MAX][MAX];
    memcpy(temp, graph, sizeof(graph));
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                temp[i][j] = min(temp[i][j], temp[i][k] + temp[k][j]);
    for (i = 1; i <= n; i++)
        if (temp[i][i] < 0)
            return i;
    return 0;
}

void BellmanFord(int source, int n) {
    int stage, i, j;
    memset(dist, 0x3F, sizeof(dist));
    memset(predec, -1, sizeof(predec));
    dist[source] = 0;
    for (stage = 0; stage < n; stage++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++) {
                if ((dist[i] < INF) && (graph[i][j] != INF)) {
                    if (dist[j] > dist[i] + graph[i][j]) {
                        dist[j] = dist[i] + graph[i][j];
                        predec[j] = i;
                    }
                }
            }
    int y = source;
    for (i = 1; i <= n; i++)
        y = predec[y];
    CycLeng = 0;
    cycle[CycLeng++] = y;
    int cur = predec[y];
    while (cur != y) {
        cycle[CycLeng++] = cur;
        cur = predec[cur];
    }
    cycle[CycLeng++] = y;
    for (i = 0; i < CycLeng - i - 1; i++) {
        int temp = cycle[i];
        cycle[i] = cycle[CycLeng - i - 1];
        cycle[CycLeng - i - 1] = temp;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 100000)
                graph[i][j] = INF;
        }
    int start = FloydWarshall(n);
    if (start == 0) {
        cout << "NO" << endl;
        return 0;
    }
    BellmanFord(start, n);
    cout << "YES" << endl << CycLeng << endl;
    for (int i = 0; i < CycLeng - 1; i++)
        cout << cycle[i] << " ";
    cout << cycle[CycLeng - 1] << endl;
    return 0;
}
