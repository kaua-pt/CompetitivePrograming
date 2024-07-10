#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vii = vector<ii>;
using vi = vector<int>;

const vii dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

#define all(x) x.begin(), x.end()

int solve()
{
    unordered_set<string> conj;
    int number;
    string s, isGood;
    cin >> s >> isGood >> number;
    for (int i = 0; i < s.length(); i++)
    {
        int bd = 0;
        for (int j = i; j <= s.length(); j++)
        {
            if (!(isGood[s[j] - 'a'] - '0'))
                bd++;
            if (bd > number)
                break;

            if (j == i)
                conj.insert(s.substr(i, 1));
            else
                conj.insert(s.substr(i, j - i + 1));
        }
    }
    return conj.size();
}

int32_t main()
{
    cout << solve() << endl;
    return 0;
}