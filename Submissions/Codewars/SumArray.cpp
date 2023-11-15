#include <vector>

int sum(std::vector<int> nums)
{
    int sum = 0;
    for (int elem : nums)
        sum += elem;
    return sum;
}