#include <bits/stdc++.h>
using namespace std;

#define qmin priority_queue<int, vi, greater<int>>

int GetBits(int n)
{
    int ans = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        ans++;
    }
    return ans;
}

// estabilidade
vector<int> sortByBits(vector<int> arr)
{
    std::sort(arr.begin(), arr.end(), [](const int &a, const int &b)
              { int bA = GetBits(a);
                int bB = GetBits(b);
                if(bA == bB) return a < b;
                return bA < bB; });
    return arr;
}