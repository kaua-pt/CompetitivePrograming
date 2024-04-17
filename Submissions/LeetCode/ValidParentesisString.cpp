#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    //  RESUMO
    // openmin - minimo possivel de parenteses que podem estar abertos
    // max - maximo tanana
    bool checkValidString(string s)
    {
        int openMin = 0, openMax = 0;
        for (auto c : s)
        {
            if (c == '(')
            {
                openMin++;
                openMax++;
            }
            if (c == ')')
            {
                openMin--;
                openMax--;
            }
            // o minimo que podem estar abertos diminui, já que teremos um *
            // maximo que pode ser fechado aumenta por causa disso *
            if (c == '*')
            {
                openMin--;
                openMax++;
            }

            // aqui é game over, tem mais fechamento do que outro
            if (openMax < 0)
                return false;
            if (openMin < 0)
                openMin = 0;
        }
        return openMin == 0;
    }
};