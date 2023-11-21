#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve()
{
    int n;
    cin >> n;
    return (n % 3 == 1 || n % 3 == 2) ? 1 : 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cout << (solve() == 1 ? "First" : "Second") << endl;

    return 0;
}