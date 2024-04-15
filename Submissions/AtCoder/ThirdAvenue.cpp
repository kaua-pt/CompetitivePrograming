#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pp = pair<int, int>;

pp findEnd(vector<int> grid, pp begin)
{
}

int bfs(vector<string> grid, pp begin)
{
    set<pp> visited;
    queue<pp, int> q;

    visited.insert(begin);
    q.push(make_pair(begin, 0));

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
    }
}

int solve()
{
    int W, H, ans;
    pp begin;
    cin >> H >> W;
    vector<string> grid;

    for (int i = 0; i < H; i++)
        cin >> grid[i];

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (grid[i][j] == 'S')
                begin = make_pair(i, j);

    bfs(grid, begin);

    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int T = 1;

    while (T--)
        cout << solve() << endl;
    return 0;
}
