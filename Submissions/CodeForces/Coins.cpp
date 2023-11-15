#include <bits/stdc++.h>
using namespace std;
typedef list<int> li;

int solve(string s)
{
    int coins = 0, coinsA = 0;
    while (true)
    {
        char aux = 'p';
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '\0')
                break;

            if (aux == 'A' && s[i] == 'B')
            {
                coins++;
                s[i] = 'B';
                s[i - 1] = 'C';
            }
            if (aux == 'B' && s[i] == 'A')
            {
                coins++;
                s[i] = 'C';
                s[i - 1] = 'B';
            }
            aux = s[i];
        }
        if (coins == coinsA)
            return coins;
        coinsA = coins;
    }
}

int main()
{
    int n;
    string str;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        int ans = solve(str);
        cout << ans << endl;
    }

    return 0;
}