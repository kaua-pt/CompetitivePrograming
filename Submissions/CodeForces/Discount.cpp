#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int A, B;
    float C;

    cin >> A >> B;
    C = (((float)A - B) / A) * 100;

    cout << setprecision(10) << C << endl;

    return 0;
}