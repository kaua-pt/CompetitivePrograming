#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> reverseGraph(vector<vector<int>> &edges)
    {
        vector<vector<int>> ans(edges.size());
        for (int i = 0; i < edges.size(); i++)
            ans[edges[i][0]].push_back(edges[i][1]);
        return ans;
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> reversedGraph = reverseGraph(edges);
        vector<vector<int>> ans(n);

        for (int i = 0; i < n; i++)
        {
            ans[i] = reversedGraph[i];
            for (int j = 0; j < reversedGraph[i].size(); j++)
                if (!reversedGraph[ans[i][j]].empty())
                    for (int z = 0; z < reversedGraph[j].size(); z++)
                    {
                        
                        ans[i].push_back(reversedGraph[j][z]);
                        // ver se ja tem no vetor
                    }
            sort(ans.begin(), ans.end());
        }

        return ans;
    }
};