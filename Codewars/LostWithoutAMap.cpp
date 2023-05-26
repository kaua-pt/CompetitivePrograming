#include <vector>

std::vector<int> maps(const std::vector<int> &values)
{
    std::vector<int> r;
    int i = 0;
    for (int el : values)
        r.insert(r.end(), el * 2);
    return r;
}