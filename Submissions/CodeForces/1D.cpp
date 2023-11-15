#include <bits/stdc++.h>
using namespace std;
typedef list<int> li;

int solve(string s, int n, int k)
{
    int jump = 0, ans = 0;
    for (auto elem : s)
    {
        if (elem == '\0')
            return ans;
        if (jump)
        {
            jump--;
            continue;
        }
        if (elem == 'B')
        {
            jump = k;
            ans++;
        }
    }
}

int main()
{
    int N;
    string str;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n, k;
        cin >> n, k;
        cin >> str;
        int ans = solve(str, n, k);
        cout << "minha ans " << ans << endl;
    }

    return 0;
}