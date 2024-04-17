#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

class Solution
{
public:
    // indice do mais perto + peso
    struct CompareFirst
    {
        bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b) const
        {
            return a.first > b.first;
        }
    };

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int size = points.size(), ans = 0;
        vector<vector<pii>> weights(points.size(), vector<pair<int, int>>());

        for (int i = 0; i < size; i++)
        {
            // iterar sobre os pontos
            for (int j = 0; j < size; j++)
            {
                if (i == j)
                    continue;
                // i-th é a o no inicial, o resto é no
                weights[i].emplace_back(make_pair(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), j));
            }
        }

        // peso,indice
        priority_queue<pii, vector<pii>, CompareFirst> pq;
        vector<int> mark(size, 0);
        pq.push({0, 0});
        while (!pq.empty())
        {
            auto [w, i] = pq.top();
            pq.pop();
            if (mark[i] == 1)
                continue;

            mark[i] = 1;
            ans += w;

            for (int j = 0; j < weights[i].size(); j++)
                if (!mark[weights[i][j].second])
                    pq.push({weights[i][j].first, weights[i][j].second});
        }
        return ans;
    }
};