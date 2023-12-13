#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve()
{
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int N, L, n, ans = 0;
    cin >> N >> L;

    for (int i = 0; i < N; i++)
    {
        cin >> n;
        if (n >= L)
            ans++;
    }

    cout << ans << endl;

    return 0;
}