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
    vector<int> v(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < 5; i++)
    {
        sort(v.begin(), v.end());
        v[0]++;
    }

    return v[0] * v[1] * v[2];
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
