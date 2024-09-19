#include <bits/stdc++.h>
using namespace std;

// partition in asc order
int partition(vector<int> &v, int l, int r)
{
    int p = v[r], i = l;
    for (int j = i; j < r; j++)
        if (v[j] < p)
        {
            swap(v[i], v[j]);
            i++;
        }
    swap(v[i], v[r]);
    return i;
}

// pode-se achar em O(n)
// Quick select
int quickSelect(vector<int> &nums, int l, int r, int k)
{
    if (l == r)
        return nums[l];

    int idx = partition(nums, l, r);

    if (nums.size() - k == idx)
        return nums[idx];
    if (nums.size() - k < idx)
        return quickSelect(nums, l, idx - 1, k);
    return quickSelect(nums, idx + 1, r, k);
}

int findKthLargest(vector<int> nums, int k)
{
    // vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    return quickSelect(nums, 0, nums.size() - 1, k);
}
