#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// 1 se tem gato na caixa
// 0 se nao tiver

int pairing(string s, string f, int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (f[i] != s[i] && f[i] == '1')
            ans++;
    return ans;
}

int seeOne(string s, int n)
{
    int ret = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '1')
            ret++;
    return ret;
}

int solve()
{
    int n, ans = 0;
    string s, f;
    cin >> n;
    cin >> s;
    cin >> f;

    // add e remove
    int s1 = seeOne(s, n);
    int f1 = seeOne(f, n);
    ans += abs(f1 - s1);

    ans += pairing(s, f, n) - ans;

    return ans;
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