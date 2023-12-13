#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(vector<int> v, int b, int l)
{
    for (auto num : v)
    {
        int base = abs(num - b);
        int limit = abs(num - l);
        base > limit ? cout << l : cout << b;
        cout << " ";
    }
    cout << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int N, L, R;
    cin >> N >> L >> R;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    solve(v, L, R);

    return 0;
}