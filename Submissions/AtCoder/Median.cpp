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
#define ssort(x) sort(all(x))

const vii dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int solve()
{
    int n;
    cin >> n;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int a,b,c;
    cin >> a >> b >> c;

    (a <= b && b <= c) || (b<= a && c<= b) ? cout << "Yes" << endl : cout << "No" << endl;

    return 0;
}
