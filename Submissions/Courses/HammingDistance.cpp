#include <bits/stdc++.h>
using namespace std;

int hammingDistance(int x, int y)
{
    return __builtin_popcount(x ^ y);
}