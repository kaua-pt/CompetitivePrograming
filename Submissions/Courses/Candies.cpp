#include <bits/stdc++.h>
using namespace std;

// O(nlogn)
int distributeCandies(vector<int> candies)
{
    set<int> s;
    for (auto candy : candies)
        s.insert(candy);
    return s.size() >= candies.size() / 2 ? candies.size() / 2 : s.size();
}