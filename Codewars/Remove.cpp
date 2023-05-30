#include <string>

using namespace std;

string sliceString(string str)
{
    int len = str.length();
    return str.substr(1, len - 2);
}