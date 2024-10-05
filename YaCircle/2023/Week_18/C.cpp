#include <iostream>
#include <vector>

using namespace std;

vector<int> CPF(const string& patt) {
    int m = patt.length();
    vector<int> pui(m, 0);
    for (int i = 1; i < m; i++) {
        int j = pui[i - 1];
        while (j > 0 && patt[i] != patt[j]) {
            j = pui[j - 1];
        }
        if (patt[i] == patt[j]) {
            j++;
        }
        pui[i] = j;
    }
    return pui;
}

void kmpSearch(const string& text, const string& patt) {
    vector<int> pui = CPF(patt);
    int n = text.length();
    int m = patt.length();
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != patt[j]) {
            j = pui[j - 1];
        }
        if (text[i] == patt[j]) {
            j++;
        }
        if (j == m) {
            cout << i - m + 1 << " ";
            j = pui[j - 1];
        }
    }
}

int main() {
    string text, patt;
    cin >> text >> patt;
    kmpSearch(text, patt);
    return 0;
}
