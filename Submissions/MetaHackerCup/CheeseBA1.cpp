#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// pao = 1+ tenho
// queijo = k
// hamburger = k

int solve()
{
    int s, d, k, qh;
    cin >> s >> d >> k;
    return (2 * (s + d) >= k + 1) && 2 * d + s >= k ? 1 : 0;
}

int main()
{
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cout << "Case #" << i + 1 << ": " << (solve() == 1 ? "YES" : "NO") << endl;

    return 0;
}