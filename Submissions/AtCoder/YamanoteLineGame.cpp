#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
#define vi vector<int>
#define si set<int>
#define mii unordered_map<int, int>
#define mci unordered_map<char, int>
#define qmax priority_queue<int>
#define qmin priority_queue<int, vi, greater<int>>
#define all(x) x.begin(), x.end()

const vii dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int T;
    cin >> T;
    int size = (2 * T) + 2;
    vector<bool> a(size);
    a[1] = true;
    cout << 1 << endl;

    int n = -1;
    while (true)
    {
        cin >> n;
        if (!n)
            break;
        a[n] = true;
        for (int i = 0; i <= size; i++)
            if (!a[i])
            {
                cout << i << endl;
                break;
            }
    }

    return 0;
}
