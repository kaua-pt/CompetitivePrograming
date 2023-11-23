#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve()
{
    int n, max = -1001, sum = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int j = 0; j < n - 1; j++)
    {
        sum += v[j];
        if (sum < max)
            max = sum;

        if (v[j])
    }
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