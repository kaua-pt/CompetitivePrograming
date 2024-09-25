#include <bits/stdc++.h>
using namespace std;

vector<int> decode(vector<int> encoded, int first)
{
    vector<int> decoded(encoded.size() + 1);
    decoded[0] = first;
    for (int i = 1; i <= encoded.size(); i++)
        decoded[i] = decoded[i - 1] ^ encoded[i - 1];
    return decoded;
}