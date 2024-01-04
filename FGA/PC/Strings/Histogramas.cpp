#include <bits/stdc++.h>

using namespace std;

void mapHisto(string S)
{
    map<char, int> hist;

    for (char s : S)
        ++hist[s];
}

void arrayHisto(string S)
{
    vector<int> a(256, 0);

    for (char s : S)
        ++a[s];
}

// 26 letras maiusculas
void array26Histo(int h[26], string S)
{
    memset(h, 0, sizeof(h));

    for (char s : S)
        ++h[s - 'A'];
}