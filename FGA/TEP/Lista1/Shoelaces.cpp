#include <bits/stdc++.h>
using namespace std;
typedef list<int> li;

int solve(vector<li> adj, int a)
{
    bool a = true;
    while (a)
    {
        list<int> listF;
        for (int h = 0; h < adj.size(); h++)
        {
            if (adj[h].size() == 1)
            {
                listF.emplace_back(h);
                adj.erase(adj.begin() + h);
            }
        }
        for (int i = 0; i < adj.size(); i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                        }
        }
    }
}

int main()
{
    int al, cad;
    cin >> al >> cad;
    vector<li> adj(al);
    for (int i = 0; i < cad; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = solve(adj, al);

    cout << ans << endl;

    return 0;
}