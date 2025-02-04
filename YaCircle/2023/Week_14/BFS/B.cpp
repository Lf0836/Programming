#include <iostream>
#include <queue>
#include <set>
#include <list>

using namespace std;

struct Vertex {
    int cost;
    int id;
};

bool operator< (const Vertex &v1, const Vertex &v2) {
    return v1.cost > v2.cost;
}

void findShortestPath(int N, int M, int start_x, int start_y, int goal_x, int goal_y, string grid[]) {
    int size = N * M;
    int start = (start_x - 1) * M + (start_y - 1);
    int goal = (goal_x - 1) * M + (goal_y - 1);

    priority_queue<Vertex> queue;
    queue.push({0, start});

    Vertex visited[size];
    for (int i = 0; i < size; i++) {
        visited[i] = {-1, -1};
    }

    while (!queue.empty()) {
        auto curr = queue.top();
        queue.pop();
        if (curr.id == goal) {
            break;
        }

        multiset<Vertex> vertices;
        int x = curr.id / M;
        int y = curr.id % M;

        if (grid[x][y] == '#') {
            continue;
        }

        if (y + 1 < M && grid[x][y + 1] != '#') {
            vertices.insert({(grid[x][y + 1] == 'W') ? 2 : 1, curr.id + 1});
        }
        if (y - 1 >= 0 && grid[x][y - 1] != '#') {
            vertices.insert({(grid[x][y - 1] == 'W') ? 2 : 1, curr.id - 1});
        }
        if (x + 1 < N && grid[x + 1][y] != '#') {
            vertices.insert({(grid[x + 1][y] == 'W') ? 2 : 1, curr.id + M});
        }
        if (x - 1 >= 0 && grid[x - 1][y] != '#') {
            vertices.insert({(grid[x - 1][y] == 'W') ? 2 : 1, curr.id - M});
        }

        for (auto next : vertices) {
            int new_cost = curr.cost + next.cost;
            if (visited[next.id].cost == -1 || visited[next.id].cost > new_cost) {
                queue.push({new_cost, next.id});
                visited[next.id].cost = new_cost;
                visited[next.id].id = curr.id;
            }
        }
    }

    cout << visited[goal].cost << endl;
    if (visited[goal].cost == -1) {
        return;
    }

    list<char> way;
    int curr = goal;
    while (curr != start) {
        int diff = curr - visited[curr].id;
        if (diff == 1) {
            way.push_front('E');
        } else if (diff == -1) {
            way.push_front('W');
        } else if (diff == M) {
            way.push_front('S');
        } else if (diff == -M) {
            way.push_front('N');
        }
        curr = visited[curr].id;
    }

    for (char x : way) {
        cout << x;
    }
}

int main() {
    int N, M, start_x, start_y, goal_x, goal_y;
    cin >> N >> M >> start_x >> start_y >> goal_x >> goal_y;

    string grid[N];
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    findShortestPath(N, M, start_x, start_y, goal_x, goal_y, grid);

    return 0;
}