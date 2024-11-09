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

    string s;
    int n;
    cin >> n;
    cin >> s;
    cout << s[n - 1] << endl;
    return 0;
}
