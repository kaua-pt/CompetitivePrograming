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
#define ssort(x) sort(all(x))

const vii dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int solve()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);

    for (int i = 0; i < h; i++)
        cin >> s[i];

    ii p1 = {-1, -1};
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] == 'o')
            {
                if (p1.first != -1)
                {
                    return abs(p1.first - i) + abs(p1.second - j);
                }
                p1.first = i;
                p1.second = j;
            }
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cout << solve() << endl;
    return 0;
}
