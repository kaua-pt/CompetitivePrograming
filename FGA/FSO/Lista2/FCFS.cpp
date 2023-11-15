#include <bits/stdc++.h>

typedef struct Process
{
    int id;
    int numDeInstructions;
    int instructions[105];
} Process;

using namespace std;

void solve(queue<Process> q)
{
    int time = 0;
    // enquanto a fila for fazia
    while (!q.empty())
    {
        // se a instruição for zero
        if (!q.front().instructions[0])
        {
            time += 10;
            q.front().numDeInstructions--;

            // se o numero de instruções for zero
            if (!q.front().numDeInstructions)
            {
                cout << q.front().id << " (" << time << ") " << endl;
                q.pop();
                continue;
            }

            // shift no array
            for (int i = 0; i < q.front().numDeInstructions; i++)
            {
                q.front().instructions[i] = q.front().instructions[i + 1];
            }
        }
        else
        {
            Process p = q.front();
            q.pop();
            p.instructions[0] = 0;
            q.push(p);
        }
    }
}

int main()
{
    int N;
    cin >> N;
    Process num[N];
    queue<Process> q;

    for (int i = 0; i < N; i++)
    {
        num[i].id = i + 1;
        cin >> num[i].numDeInstructions;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < num[i].numDeInstructions; j++)
        {
            cin >> num[i].instructions[j];
        }
        q.push(num[i]);
    }

    solve(q);

    return 0;
}