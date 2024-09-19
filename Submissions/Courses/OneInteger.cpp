#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
#define vi vector<int>
#define si set<int>
#define mii unordered_map<int, int>
#define mci unordered_map<char, int>
#define qmax priority_queue<int>
#define qmin priority_queue<int, vi, greater<int>>
#define all(x) x.begin(), x.end()

int solve(vector<int> nums)
{
    int sum = 0;
    qmin q;
    for (auto e : nums)
        q.push(e);

    while (q.size() > 1)
    {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();

        sum += a + b;
        q.push(a + b);
    }
    return sum;
}
