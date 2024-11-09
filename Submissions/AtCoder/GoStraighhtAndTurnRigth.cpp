#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
#define vi vector<int>
#define si set<int>
#define mii unordered_map<int, int>
#define mci unordered_map<char, int>
#define qmax priority_queue<int>
#define qmin priority_queue<int, vi, greater<int>>
#define all(x) x.begin(), x.end()

const vii dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

ii solve(string s)
{
    ii result = {0, 0};
    int dir = 0;
    for (char i : s)
    {
        if (s[i] == 'S')
        {
            if (dir == 0)
                result.first++;
            else if (dir == 1)
                result.second--;
            else if (dir == 2)
                result.first--;
            else
                result.second++;

            continue;
        }
        if (s[i] == 'R')
        {
            dir = (dir + 1) % 4;
            continue;
        }
    }
    return result;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n;
    string s;

    cin >> n >> s;

    ii p = solve(s);

    cout << p.first << " " << p.second << endl;

    return 0;
}
