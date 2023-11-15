#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, ans = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
        if (i & 1)
            ans++;

    cout << setprecision(6) << ans / N << endl;

    return 0;
}