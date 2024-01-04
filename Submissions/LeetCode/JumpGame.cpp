#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int len = nums.size();
        for (int i = 0; i + 1 != len; i += nums[i])
            if (i > len || !nums[i])
                return false;
        return true;
    }
};