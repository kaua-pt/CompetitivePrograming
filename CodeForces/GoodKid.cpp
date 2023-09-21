#include <bits/stdc++.h>
using namespace std;
typedef list<int> li;
typedef long long ll;

int solve(string s)
{
}

int main()
{
    int N, n, p;
    ll prod;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            cin >> p;
            v.push_back(p);
        }

        sort(v.begin(), v.end());
        prod = 1;
        v[0]++;

        for (int k = 0; k < n; k++)
        {
            prod *= v[k];
        }
        cout << prod << endl;
    }

    return 0;
}