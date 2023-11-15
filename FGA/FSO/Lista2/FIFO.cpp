#include <bits/stdc++.h>

using namespace std;

int hasNumber(int n, list<int> l)
{
    for (int num : l)
        if (num == n)
            return 1;
    return 0;
}

int solve(int N, int P)
{
    int pageF = 0, n;
    queue<int> q;
    list<int> l;

    while (P)
    {
        cin >> n;
        if (!hasNumber(n, l))
        {
            if (q.size() == N)
            {

                pageF++;
                l.remove(q.front());
                q.pop();
                q.push(n);
                l.push_back(n);
            }
            else
            {
                q.push(n);
                l.push_back(n);
            }
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