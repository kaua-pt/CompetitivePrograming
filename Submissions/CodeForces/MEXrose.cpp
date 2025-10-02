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
    int n, k, ans = 0, last = -1;
    cin >> n >> k;
    vi v(n);
    for (size_t i = 0; i < n; i++)
        cin >> v[i];

    ssort(v);

    for (size_t i = 0; i < n; i++)
    {
        if (v[i] > k)
            break;

        if (v[i] == k)
        {
            ans++;
            continue;
        }

        // different and < k

        last = v[i];
    }
    return 0;
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
