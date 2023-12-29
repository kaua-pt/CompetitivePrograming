#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    string s;
    int len;
    cin >> len;
    cin >> s;

    for (int i = 0; i < len;)
    {
        cout << s[i] << s[i + 1];
        if (s[i + 2] == 'a' || s[i + 2] == 'e')
        {
            cout << ".";
            i += 2;
            continue;
        }
        else
        {
            cout << s[i + 2];
            i += 3;
            continue;
        }
    };
    cout << endl;
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