#include <string>

std::string fakeBin(std::string str)
{
    std::string ret = "";
    for (char a : str)
    {
        if ((a - '0') >= 5)
            ret += '1';
        else
            ret += '0';
    }
    return ret;
}