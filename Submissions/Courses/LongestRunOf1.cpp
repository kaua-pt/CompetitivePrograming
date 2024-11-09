#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
    int ans = 0, run = 0;
    while (n > 0)
    {
        if (n & 1)
            run++;
        else
        {
            if (ans < run)
                ans = run;
            run = 0;
        }

        n >>= 1;
    }

    if (ans < run)
        ans = run;
    return ans;
}