#include <bits/stdc++.h>
using namespace std;
typedef list<int> li;

int solve(string s)
{
    if (s[0] == 'a' || s[1] == 'b' || s[2] == 'c')
        return 1;
    return 0;
}

int main()
{
    int n;
    string str;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        solve(str) == 1 ? cout << "YES" << endl : cout << "NO" << endl;
    }

    return 0;
}