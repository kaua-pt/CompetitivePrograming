#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pp = pair<int, int>;

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;

    if (!c)
        if (a <= b)
            cout << "Aoki" << endl;
        else
            cout << "Takahashi" << endl;

    if (c)
        if (b <= a)
            cout << "Takahashi" << endl;
        else
            cout << "Aoki" << endl;
}
