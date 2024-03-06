#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> v(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            v[s[i] % 26]++;
            v[t[i] % 26]++;
        }
        for (int i = 0; i < 26; i++)
            if (v[i] & 1)
                return false;

        return true;
    }
};