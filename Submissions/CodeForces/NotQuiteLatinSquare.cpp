#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    string s;
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        cin >> s;
        if (s.find("?") != string::npos)
        {
            for (int j = 0; j < 3; j++)
                sum += s[j];
            cout << (char)((sum - 261) * -1) << endl;
        }
    }
    return;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        solve();
    return 0;
}