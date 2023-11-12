#include <bits/stdc++.h>
using namespace std;

int solve()
{
    int ch, key, st, sec = 0;
    cin >> ch >> key >> st;

    return ch > key ? ch : key + max(0, key - ch - st);
}

int main()
{

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cout << solve() << endl;

    return 0;
}