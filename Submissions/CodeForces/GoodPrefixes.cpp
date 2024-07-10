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
    int n;
    cin >> n;
    vector<ll> prefixes(n);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        prefixes.push_back(a);
    }

    ll big = 0, count = 0, sum = 0;

    for (int j = 0; j < n; j++)
    {
        if (prefixes[j] >= big)
        {
            sum += big;
            big = prefixes[j];
            continue;
        }
        sum += prefixes[j];
        if (big == sum)
            count++;
    }

    if (big == sum)
        count++;

    return count;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
        cout << "ans " << solve() << endl;
    return 0;
}
