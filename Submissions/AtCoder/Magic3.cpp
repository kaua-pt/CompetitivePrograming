#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pp = pair<int, int>;

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int N, S, D;
    cin >> N >> S >> D;

    while (N--)
    {
        int x, y;
        cin >> x >> y;

        if (x < S && y > D)
        {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}
