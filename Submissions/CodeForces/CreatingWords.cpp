#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vii = vector<ii>;
using vi = vector<int>;

const vii dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

#define all(x) x.begin(), x.end()

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    char aux;
    aux = s1[0];
    s1[0] = s2[0];
    s2[0] = aux;

    cout << s1 << " " << s2 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();
    return 0;
}
