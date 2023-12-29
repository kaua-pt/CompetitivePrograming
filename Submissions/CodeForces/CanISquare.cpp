#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isPerfectSquare(ll n)
{
    double x = sqrt(n);
    return (x * x == n);
}

string solve()
{
    int N, n;
    ll S = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        S += n;
    }
    return isPerfectSquare(S) ? "YES" : "NO";
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