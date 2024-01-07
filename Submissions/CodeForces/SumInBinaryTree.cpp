#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long int;

int solve()
{
    // 1 é direita
    // 0 é esquerda
    // ignora o msb e faz com o resto
    ull n, sum = 0, add;
    cin >> n;
    sum += n;
    while (true)
    {
        int path = n & 1;

        if (path == 0)
        {
            int add = n / 2;
            sum += add;
        }
        if (path == 1)
        {
            int add = (n - 1) / 2;
            sum += add;
        }

        n = n >> 1;
        if (n == 0 || n == 1)
            break;
    }

    return sum;
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