#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve()
{
    string s;
    int n, ans = 0;
    cin >> n;
    cin >> s;
    vector<int> v(27, 0);

    for (int i = 0; i < n; i++)
    {
        int value = s[i] - 64;
        v[value]++;
    }

    for (int i = 1; i < 27; i++)
        if (v[i] >= i)
            ans++;
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cout << solve() << endl;
    return 0;
}