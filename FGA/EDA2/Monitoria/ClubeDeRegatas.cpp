#include <bits/stdc++.h>

using namespace std;

int adj[11][11];
int twisted[11];

void print(vector<int> path, int ball, int begin)
{
    if (ball == begin)
    {
        cout << ball;
        return;
    }
    if (ball == 11)
    {
        print(path, path[ball], begin);
        cout << " "
             << "99";
    }
    else
    {
        print(path, path[ball], begin);
        cout << " " << ball;
    }
}

void solve(int ball)
{
    queue<int> q;
    vector<int> path(12, -1);
    q.push(ball);
    path[ball] = ball;

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        for (int v = 0; v < 12; v++)
        {
            if (path[v] < 0 && adj[u][v] && twisted[v])
            {
                path[v] = u;
                q.push(v);
            }
        }
    }

    print(path, 11, ball);
}

int main()
{
    int ball;

    for (int i = 0; i < 10; i++)
    {
        int player, num, rel;
        char like;
        cin >> player >> like >> num;

        like == 'S' ? twisted[player] = 1 : twisted[player] = 0;

        for (int j = 0; j < num; j++)
        {
            cin >> rel;
            if (rel == 99)
                rel = 11;
            adj[player][rel] = 1;
        }
    }
    twisted[11] = 1;
    cin >> ball;

    if (ball == 99)
    {
        cout << "99" << endl;
        return 0;
    }
    solve(ball);
    cout << endl;
    return 0;
}