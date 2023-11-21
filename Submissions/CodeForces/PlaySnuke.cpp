#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    long long N, A, P, X, mn = 1000000001;
    vector<int> v;

    cin >> N;

    while (N--)
    {
        cin >> A >> P >> X;
        if ((X - A) > 0 && mn > P)
            mn = P;
    }

    cout << (mn == 1000000001 ? -1 : mn) << endl;

    return 0;
}