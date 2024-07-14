class Solution {
public:
    // // Memoization
    // int minSum(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp)
    // {
    //     // Pruning
    //     if(x < 0 || y < 0)
    //     {
    //         return INT_MAX;
    //     }

    //     // Base Case
    //     if(x == 0 && y == 0)
    //     {
    //         return grid[0][0];
    //     }

    //     // Cache Check
    //     if(dp[x][y] != -1)
    //     {
    //         return dp[x][y];
    //     }

    //     // Recursive Computations;
    //     int up = minSum(x - 1, y, grid, dp);
    //     int left = minSum(x, y - 1, grid, dp);

    //     // Cache (Save) and Return
    //     return dp[x][y] = min(up, left) + grid[x][y];
    // }

    int minPathSum(vector<vector<int>>& grid) {
        // int m = grid.size(), n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));

        // return minSum(m - 1, n - 1, grid, dp);

        // // Tabulation
        // int m = grid.size(), n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, 0));

        // dp[0][0] = grid[0][0];

        // for(int i = 0; i < m; i++)
        // {
        //     for(int j = 0; j < n; j++)
        //     {
        //         if(i == 0 && j == 0)
        //         {
        //             continue;
        //         }

        //         int temp = INT_MAX;
        //         if(i > 0)
        //         {
        //             temp = min(temp, dp[i - 1][j]);
        //         }
        //         if(j > 0)
        //         {
        //             temp = min(temp, dp[i][j - 1]);
        //         }

        //         dp[i][j] = temp + grid[i][j];
        //     }
        // }

        // return dp[m - 1][n - 1];

        // // Space Optimization - 1
        // int m = grid.size(), n = grid[0].size();
        // vector<int> prevrow(n, 0);

        // prevrow[0] = grid[0][0];

        // for(int i = 0; i < m; i++)
        // {
        //     vector<int> temp(n, 0);
        //     temp[0] = grid[0][0];
        //     for(int j = 0; j < n; j++)
        //     {
        //         if(i == 0 && j == 0)
        //         {
        //             continue;
        //         }

        //         int t = INT_MAX;
        //         if(i > 0)
        //         {
        //             t = min(t, prevrow[j]);
        //         }
        //         if(j > 0)
        //         {
        //             t = min(t, temp[j - 1]);
        //         }

        //         t += grid[i][j];
        //         temp[j] = t;
        //     }
        //     prevrow = temp;
        // }

        // return prevrow[n - 1];

        // Space Optimization - 2
        int m = grid.size(), n = grid[0].size();
        vector<int> prevrow(n, 0);

        prevrow[0] = grid[0][0];
        int prevcell = grid[0][0];

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0)
                {
                    continue;
                }

                int t = INT_MAX;
                if(i > 0)
                {
                    t = min(t, prevrow[j]);
                }
                if(j > 0)
                {
                    t = min(t, prevcell);
                }

                t += grid[i][j];
                prevrow[j] = t;
                prevcell = t;
            }
        }

        return prevcell;
    }
};