#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> hashtable;
        for (auto num : nums)
        {
            if (hashtable.count(num))
                return true;
            hashtable.insert(num);
        }
        return false;
    }
};