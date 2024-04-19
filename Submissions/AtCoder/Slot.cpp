#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pp = pair<int, int>;

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    string T;
    cin >> T;

    string ans = (T[0] == T[1]) && (T[1] == T[2]) && (T[2] == T[0]) ? "Won" : "Lost";
    cout << ans << endl;
    return 0;
}
