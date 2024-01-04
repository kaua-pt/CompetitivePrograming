#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string S)
{
    int len = S.length();
    for (int i = 0; i < len / 2; i++)
        if (S[i] != S[len - i - 1])
            return false;
    return true;
}