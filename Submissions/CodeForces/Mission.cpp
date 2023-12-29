#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve()
{
    int n, k, ans = 0, sum = 0, mx = 0; // quests e maximo que ele pode completar
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        a[i] = c;
    }
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        b[i] = c;
    }

    for (int i = 0; i < min(k, n); i++)
    {
        sum += a[i];
        mx = max(mx, b[i]);
        ans = max(ans, sum + (k - i) * mx);
    }
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