#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve()
{
    int N, sum = 0;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    sort(A.begin(), A.end());

    // soma com palindromos
    for (int j = 0; j < N / 2; j++)
        sum += A[j] - A[N - j - 1];

    return sum;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
        cout << solve() * -1 << endl;
    return 0;
}