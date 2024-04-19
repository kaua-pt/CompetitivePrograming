#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int T, ans = 1, claw;
    cin >> T;
    vector<int> claws(T);
    for (int i = 0; i < T; i++)
        cin >> claws[i];

    claw = claws[T - 1];

    for (int i = T - 2; i >= 0; i--)
    {
        if (claw == 0)
            ans++;
        claw = max(claw - 1, claws[i]);
    }
    cout << ans << endl;
    return 0;
}
