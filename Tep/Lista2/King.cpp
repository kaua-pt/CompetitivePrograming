#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
typedef pair<int, int> ii;

const vector<ii> prio
{
    ii(1, 1), ii(-1, -1), ii(1, -1), ii(-1, 1)
}

const vector<ii> dirs{
    ii(1, 0),
    ii(0, 1),
    ii(-1, 0),
    ii(0, -1)};

// a ideia é identificar qual a direcao que o caminho fica menor

void solve(string i, string f)
{
}

int main()
{
    string i, f;
    cin >> i;
    cin >> f;
    solve(i, f);
    return 0;
}