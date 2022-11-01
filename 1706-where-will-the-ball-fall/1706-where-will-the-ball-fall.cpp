class Solution
{
    public:
        vector<int> findBall(vector<vector < int>> &grid)
        {
            int n = grid.size(), m = grid[0].size();
            vector<int> ans(m, -1);
            for (int k = 0; k < m; k++)
            {
                bool ok = true;
                int i = 0, j = k;
                while (i < n and j < m)
                {
                    if (j < 0 or j >= m)
                    {
                        ok = false;
                        break;
                    }
                    if (j + 1 < m and grid[i][j] == 1 and grid[i][j + 1] == -1)
                    {
                        ok = false;
                        break;
                    }
                    if (j - 1 >= 0 and grid[i][j] == -1 and grid[i][j - 1] == 1)
                    {
                        ok = false;
                        break;
                    }
                    if (grid[i][j] == 1)
                    {
                        j++;
                    }
                    else
                    {
                        j--;
                    }
                    i++;
                }
                if (j >= m or j < 0) ok = false;
                if (ok)
                {
                    ans[k] = j;
                }
            }
            return ans;
        }
};