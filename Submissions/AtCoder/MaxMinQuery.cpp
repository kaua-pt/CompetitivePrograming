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
#define ssort(x) sort(all(x))

const vii dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct DataSet
{
    int nTotal = -1;
    vi ms;

    DataSet(int n) : ms(n) {}

    void add(int num)
    {
        nTotal++;
        ms[nTotal] = num;
        sort(ms.begin(), ms.begin() + nTotal + 1);
    }

    void print()
    {
        cout << "Vector: " << endl;
        for (int i = 0; i <= nTotal; i++)
            cout << ms[i] << " ";
        cout << endl;
        cout << ms[nTotal] - ms[0] << endl;
    }

    void remove(int num, int times)
    {
        int begin = -1, cut = 0, shift;
        for (int i = 0; i < nTotal; i++)
        {
            if (ms[i] == num)
            {
                if (begin == -1)
                    begin = i;
                else
                    cut++;
            }
        }

        if (begin == -1)
            return;

        // shift array
        shift = min(times, cut);
        ms.erase(ms.begin() + begin, ms.begin() + shift + begin);
        nTotal -= shift;
    }
};

void solve()
{
    DataSet d(2 * 10e5);
    int q, op, x, c;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> op;

        if (op == 1)
        {
            cin >> x;
            d.add(x);
        }

        if (op == 3)
            d.print();

        if (op == 2)
        {
            cout << "entrei" << endl;
            cin >> x >> c;
            d.print();
            d.remove(x, c);
        }
    }

    return;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    solve();
    return 0;
}
