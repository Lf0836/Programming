#include <iostream>

using namespace std;

int main()
{
    char letter;
    cin >> letter;
    if (letter == 'A' || letter == 'D' || letter == 'O' || letter == 'P' || letter == 'Q' || letter == 'R')
    {
        cout << 1;
    }
    else if (letter == 'B')
    {
        cout << 2;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
