#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hm;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            hm.insert(make_pair(i, nums[i]));

        for (int i = 0; i < n; i++)
        {
            if (hm.count(abs(target - nums[i])))
                return {min(i, hm.at(abs(target - nums[i]))), max(i, hm.at(abs(target - nums[i])))};
            hm[nums[i]] = i;
        }
        return {};
    }
};