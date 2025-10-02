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

int solve()
{
    int n, ans = 0;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(all(v));

    for (int j = 0; j < n; j += 2)
        ans = max(v[j + 1] - v[j], ans);
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
        cout << solve() << endl;
    return 0;
}
