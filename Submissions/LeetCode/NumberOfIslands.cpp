#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        vector<>
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int ans = 0, y = grid.size(), x = grid[0].size();
        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < x; j++)
            {
                if (grid[i][j] == '1')
                {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};