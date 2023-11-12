#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    string S;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> S;
        S.length() > 10 ? cout << S[0] << S.length() - 2 << S[S.length() - 1] << endl : cout << S << endl;
    }
    return 0;
}