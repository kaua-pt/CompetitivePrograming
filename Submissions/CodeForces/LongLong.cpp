#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n, op = 0;
    ll sum = 0;
    bool flag = false;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        if (k < 0)
        {
            sum += (k * -1);
            if (!flag)
            {
                op++;
                flag = true;
            }
        }
        if (k > 0)
        {
            if (flag)
                flag = false;
            sum += k;
        }
    }
    cout << sum << " " << op << endl;
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