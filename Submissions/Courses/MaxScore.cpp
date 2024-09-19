#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
#define vi vector<int>
#define si set<int>
#define mii unordered_map<int, int>
#define mci unordered_map<char, int>
#define qmax priority_queue<int>
#define qmin priority_queue<int, vi, greater<int>>
#define all(x) x.begin(), x.end()

// Propriedade de triangulo
// se a + b + c for um triangulo perfeito, então ele terá
// como possibilidades a soma dos 3 numeros / 2
// senao, ele só vai pegar os dois menores de operações
// ademais, é o máximo que ele pode ir

int maximumScore(int a, int b, int c)
{
    if (a + b < c)
        return a + b;
    if (b + c < a)
        return b + c;
    if (a + c < b)
        return a + c;
    return (a + b + c) / 2;
}
