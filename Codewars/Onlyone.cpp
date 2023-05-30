#include <vector>
#include <string>

bool check(const std::vector<std::string> &seq, const std::string &elem)
{
    for (auto element : seq)
        if (element == elem)
            return true;
    return false;
}