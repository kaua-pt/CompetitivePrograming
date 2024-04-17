#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int T;
    cin >> T;
    int i = T, maxSize = -1, j, h;
    ll remaining = 0;
    priority_queue<int> maxHeap;

    while (i--)
    {
        cin >> j;
        remaining += j;
    }

    i = T;
    while (i--)
    {
        cin >> h;
        maxHeap.push(h);
    }

    int max1 = maxHeap.top();
    maxHeap.pop();
    string ans = (max1 + maxHeap.top()) >= remaining ? "YES" : "NO";
    cout << ans << endl;

    return 0;
}
