#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;

char solve(int n, vi v1, vi v2)
{
    char ans;

    for (int i = 2; i < n + 1; i++)
    {
        v1[v2[i]] = v1[v2[i]] + v1[i];
    }

    cout << endl;

    for (int j = 1; j <= n; j++)
    {
        cout << v1[j] << " ";
    }

    cout << endl;
    cout << endl;

    return '-';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> v1(N + 1);
    vector<int> v2(N + 1);

    for (int i = 1; i < N + 1; i++)
    {
        int h;
        cin >> h;
        v1[i] = h;
    }

    for (int j = 2; j < N + 1; j++)
    {
        int h;
        cin >> h;
        v2[j] = h;
    }

    cout << solve(N, v1, v2) << endl;

    return 0;
}