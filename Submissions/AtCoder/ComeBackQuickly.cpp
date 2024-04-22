#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pp = pair<int, int>;

int dijkstra(vector<vector<pp>> g, int i)
{
    queue<int> q;
    priority_queue<pp, vector<pp>, greater<>> pq;
    vector<int> d(g.size(), 1e9);

    // auto valor do primeiro elemento
    q.push(i);
    for (int j = 0; j < g[i].size(); j++)
        if (g[i][j].first == i)
            d[i] = g[i][j].second;

    while (!q.empty())
    {
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<vector<pp>> g(N);
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    for (int i = 0; i < N; i++)
        cout << dijkstra(g, i) << endl;
    return 0;
}
