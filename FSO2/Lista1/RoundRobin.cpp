#include <bits/stdc++.h>

using namespace std;

typedef struct Process
{
    int id, time;
} Process;

int Quantum;

void solve(vector<Process> v)
{
    int run = 0, actual = 0, max = v.size() - 1;
    while (max > 0)
    {
        run += Quantum;
        v[actual].time -= Quantum;

        if (v[actual].time <= 0)
        {
            // correct time
            run += v[actual].time;
            std::cout << v[actual].id << " (" << run
                      << ")"
                      << "\n";

            // shift vector
            for (int i = actual; i < max; i++)
            {
                v[i] = v[i + 1];
            }
            max--;
        }
        else
            actual++;
            
        if (actual == max + 1)
            actual = 0;
    }

    // otimizar o ultimo
    std::cout << v[0].id << " (" << v[0].time + run
              << ")"
              << "\n";
}

int main()
{
    int N;
    cin >> N;
    vector<Process> v(N);
    cin >> Quantum;

    for (int i = 0; i < N; i++)
    {
        Process p;
        cin >> p.id >> p.time;
        p.time *= 1000;
        v[i] = p;
    }

    solve(v);

    return 0;
}