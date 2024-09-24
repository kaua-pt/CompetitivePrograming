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

vector<int> findClosestElements(vector<int> arr, int k, int x)
{
    // find x
    int n = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == x)
        {
            n = i;
            break;
        }
    }

    vector<int> ret;
    int j = n - 1, l = n + 1;
    while (k)
    {
        if (abs(arr[j] - arr[n]) > abs(arr[l] - arr[n]))
        {
            ret.push_back(arr[n]);
            l++;
        }
        else
        {
            ret.push_back(arr[j]);
            j--;
        }
        k--;
    }
    sort(all(ret));
    return ret;
}
