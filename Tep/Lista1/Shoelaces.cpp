#include <bits/stdc++.h>
using namespace std;
typedef list<int> li;

int solve(vector<li> adj, int a)
{
    priority_queue<int> nodes();
    int a = 1, groups = 0;
    for (li list : adj)
    {
        nodes[a] = list.size();
        a++;
    }

    for (int a = 0; a < nodes.size(); a++)
    {
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