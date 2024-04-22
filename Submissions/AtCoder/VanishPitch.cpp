#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pp = pair<int, int>;

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int V, T, S, D;
    cin >> V >> T >> S >> D;

    if ((D > V * S) || (D < V * T))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
