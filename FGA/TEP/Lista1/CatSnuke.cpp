#include <bits/stdc++.h>
using namespace std;

int bfs(int s, int n, vector<vector<int>> adj)
{
    vector<int> dist(n + 1, 1e7);
    queue<int> q;
    dist[s] = 0;
    q.push(s);

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    return dist[n];
}

int solve(vector<vector<int>> adj, int N)
{
    int dist = bfs(1, N, adj);
    return dist == 2 ? 1 : 0;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    int ans = solve(adj, N);

    if (ans == 1)
        cout << "POSSIBLE"
             << "\n";
    else
        cout << "IMPOSSIBLE"
             << "\n";

    return 0;
}