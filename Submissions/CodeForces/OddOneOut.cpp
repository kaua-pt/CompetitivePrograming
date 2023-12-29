#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    return a == b ? c : b == c ? a
                               : b;
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