#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vii = vector<ii>;
using vi = vector<int>;

const vii dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

#define all(x) x.begin(), x.end()

int solve()
{
    int n, sum = 0;
    cin >> n;

    if (n == 3)
        return 3;
    return 2;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int T, n;
    cin >> T;

    while (T--)
    {
        cin >> n;
        cout << ((n == 3) ? 3 : 2) << endl;
    }
    return 0;
}
