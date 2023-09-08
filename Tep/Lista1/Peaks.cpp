#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

int solve(vector<int> H, int N, int M)
{
    int count = 0;
    bitset<MAX> bt(N);
    bt.set(); // tudo 1
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        if (H[a] < H[b])
            bt[a - 1] = 0;
        if (H[b] < H[a])
            bt[b - 1] = 0;
        if (H[b] == H[a])
        {
            bt[a - 1] = 0;
            bt[b - 1] = 0;
        }
    }

    for (int h = 0; h < N; h++)
    {
        if (bt[h] == 1)
            count++;
    }

    return count;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> H(N + 1);
    for (int i = 0; i < N; i++)
    {
        int p;
        cin >> p;
        H[i + 1] = p;
    }
    int ans = solve(H, N, M);

    cout << ans << endl;

    return 0;
}