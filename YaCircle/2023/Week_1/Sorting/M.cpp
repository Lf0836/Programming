#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int level;
    vector<Node*> children;
};

void countLevels(Node* root, vector<int>& levels) {
    if (root == nullptr) {
        return;
    }
    levels[root->level]++;
    for (Node* child : root->children) {
        countLevels(child, levels);
    }
}

int main() {
    int N;
    cin >> N;
    vector<Node*> nodes(N);
    vector<int> levels(N, 0);
    for (int i = 0; i < N; i++) {
        int C;
        cin >> C;
        Node* node = new Node();
        node->level = i;
        if (i > 0) {
            int parentIndex = (i - 1) / 2;
            nodes[parentIndex]->children.push_back(node);
        }
        nodes[i] = node;
    }
    countLevels(nodes[0], levels);
    for (int i = 0; i < N; i++) {
        cout << levels[i] << " ";
    }
    return 0;
}
