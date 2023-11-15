#include <stdio.h>
#include <stdlib.h>

long long int nums[81] = {0};
long int fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;

    if (nums[n] != 0)
        return nums[n];

    nums[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return nums[n];
}
