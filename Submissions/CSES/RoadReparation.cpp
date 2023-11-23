#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// mst

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int cit, road, a, b, c;
    cin >> cit >> road;

    int v[cit][cit];

    for (int i = 0; i < road; i++)
    {
        cin >> a >> b >> c;
        v[a][b] = c;
    }

    return 0;
}