#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pp;

void solve()
{
    int q, n;
    cin >> q >> n;
    vector<int> a(q);
    vector<pp> x(n);
    for (int i = 0; i < q; i++)
    {
        int h;
        cin >> h;
        a[i] = h;
    }

    for (int j = 0; j < n; j++)
    {
        pp par;
        cin >> par.first;
        par.second = 1 << par.first;
        x[j] = par;
    }

    sort(x.begin(), x.end());

    for (int i = 0; i < q; i++)
        for (int j = 0; j < n; j++)
            if (a[i] % x[j].second == 0)
            {
                a[i] += x[j].first;
                break;
            }

    for (int i = 0; i < q; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        solve();
    return 0;
}