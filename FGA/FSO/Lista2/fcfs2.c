#include <stdio.h>
#include <stdlib.h>

typedef struct Process
{
    int id;
    int numDeInstructions;
    int instructions[105];
} Process;

void solve(Process *q, int N)
{
    int time = 0;

    while (N > 0)
    {
        if (q->instructions[0] == 0)
        {
            time += 10;
            q->numDeInstructions--;

            if (q->numDeInstructions == 0)
            {
                printf("%d (%d)\n", q->id, time);
                N--;
                q++;
                continue;
            }

            for (int i = 0; i < q->numDeInstructions; i++)
            {
                q->instructions[i] = q->instructions[i + 1];
            }
        }
        else
        {
            Process p = *q;
            N--;
            q++;

            p.instructions[0] = 0;
            *q = p;
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    Process *num = (Process *)malloc(N * sizeof(Process));

    for (int i = 0; i < N; i++)
    {
        num[i].id = i + 1;
        scanf("%d", &num[i].numDeInstructions);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < num[i].numDeInstructions; j++)
        {
            scanf("%d", &num[i].instructions[j]);
        }
    }

    solve(num, N);

    free(num);

    return 0;
}
