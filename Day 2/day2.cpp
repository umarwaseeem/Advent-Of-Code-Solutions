#include <bits/stdc++.h>
using namespace std;

int main()
{
    std ::map<char, int> player1({{'A', 1}, {'B', 2}, {'C', 3}});
    std ::map<char, int> player2({{'X', 1}, {'Y', 2}, {'Z', 3}});

    char p1;
    char p2;

    int score = 0;

    int x = 0;

    while (cin >> p1 >> p2)
    {
        score += player2[p2];

        if (player1[p1] == player2[p2])
        {
            score += 3;
        }
        else if ( (p1 == 'A' && p2 == 'Y') || (p1 == 'B' && p2 == 'Z') || (p1 == 'C' && p2 == 'X'))
        {
            score += 6;
        }
    }

    cout << score;
}