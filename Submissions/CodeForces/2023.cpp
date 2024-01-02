#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll h = 1;
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int g;
        cin >> g;
        h *= g;
    }

    int mod = 2023 % h;

    if (mod != 0)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;

    set<int> s = {7, 17, 2023};
    for (int i = 0; i < k; i++)
    {
        for (auto j : s)
        {
            if (mod == 1)
                break;
            if (mod % j == 0)
            {
                mod /= j;
                cout << j << " ";
                break;
            }
        }
        if (mod == 1)
            cout << 1 << " ";
    }
    cout << endl;
    return;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();
    return 0;
}