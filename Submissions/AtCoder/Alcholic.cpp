#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pp = pair<int, int>;

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int L, D, lim = 0;
    cin >> L >> D;
    D *= 100;

    for (int i = 0; i < L; i++)
    {
        int a, b;
        cin >> a >> b;

        lim += a * b;

        if (lim > D)
        {
            cout << i + 1 << '\n';
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
