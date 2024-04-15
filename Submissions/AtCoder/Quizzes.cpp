#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    string s;
    int N, P;
    cin >> N >> P >> s;

    for (auto c : s)
        if (c == 'o')
            P++;
        else
            P = max(P - 1, 0);

    cout << P << endl;

    return 0;
}
