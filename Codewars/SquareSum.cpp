#include <vector>

int square_sum(const std::vector<int> &numbers)
{
    int sum = 0;
    for (int element : numbers)
    {
        sum += element * element;
    }
    return sum;
}