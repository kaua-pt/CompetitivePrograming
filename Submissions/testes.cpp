#include <bits/stdc++.h>
#include <thread>
#include <chrono>

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

const vii dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void oddOrEven()
{
    int i = 0;

    while (true)
    {
        if (i & 1)
            cout << i << endl;
    }
}

int32_t main()
{
    std::thread t(oddOrEven);

    return 0;
}
