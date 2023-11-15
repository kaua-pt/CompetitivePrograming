#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

// bfs

int solve(vector<vector<int>> adj, int S, int T, int N)
{
    vector<int> pass(N + 1, -1);
    queue<int> q;
    pass[S] = 0;
    q.push(S);

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (pass[v] < 0)
            {
                pass[v] = pass[u] + 1;
                q.push(v);
            }
        }
    }

    if (pass[T] < 0 || pass[T] % 3 != 0)
        return -1;
    return pass[T];
}

int main()
{
    int N, M, S, T;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    cin >> S >> T;

    int ans = solve(adj, S, T, N);
    cout << ans << "\n";
    return 0;
}