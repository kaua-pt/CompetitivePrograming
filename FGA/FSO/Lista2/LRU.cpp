#include <bits/stdc++.h>

using namespace std;

int hasNumber(int n, vector<int> l)
{
    for (int p : l)
        if (p == n)
            return 1;
    return 0;
}

int getPosition(int n, vector<int> l)
{
    for (int i = 0; i < l.size(); i++)
        if (l[i] == n)
            return i;
}

int solve(int N, int P)
{
    int pageF = 0, n;
    vector<int> l;

    while (P)
    {
        cin >> n;

        if (!hasNumber(n, l))
        {
            if (l.size() == N)
            {
                l.erase(l.begin());
                l.push_back(n);
                pageF++;
            }
            else
                l.push_back(n);
        }
        else
        {
            int pos = getPosition(n, l);
            l.erase(l.begin() + pos);
            l.push_back(n);
        }

        P--;
    }
    return pageF + N;
}

int main()
{
    int N, P;
    cin >> N;
    cin >> P;

    cout << solve(N, P) << endl;

    return 0;
}