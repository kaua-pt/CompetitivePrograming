#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve()
{
    int x, x1, y, y1, x2, y2;
    cin >> x >> y;
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    int result = (max(max(x1, x2), x) - min(min(x1, x2), x)) * (max(max(y1, y2), y) - min(min(y1, y2), y));
    cin >>
        x >> y;
    return result;
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