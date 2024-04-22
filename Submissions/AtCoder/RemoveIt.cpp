#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pp = pair<int, int>;

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int N, T, j = 0;
    cin >> N >> T;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        if (a != T)
        {
            v[j] = a;
            j++;
        }
    }

    if (v.empty())
        cout << "\n";
    else
    {
        for (int i = 0; i < j; i++)
        {
            cout << v[i] << " ";
        }
    }

    return 0;
}
