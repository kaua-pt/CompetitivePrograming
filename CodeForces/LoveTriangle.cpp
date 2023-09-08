#include <bits/stdc++.h>

using namespace std;

int solve(int n, const vector<int> &vetor)
{
    for (int g = 1; g < n; ++g)
    {
        int b = vetor[g];
        int c = vetor[b];

        if (vetor[c] == g)
            return 1;
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;

    vector<int> vetor(n + 1);

    for (int i = 0; i < n; i++)
        cin >> vetor[i];

    int ans = solve(n, vetor);

    cout << (ans ? "YES" : "NO") << "\n";
    return 0;
}