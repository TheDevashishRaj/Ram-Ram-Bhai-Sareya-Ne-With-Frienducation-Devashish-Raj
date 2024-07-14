class Solution {
public:
    // // Memoization
    // int maxsq(int i, int j, vector<vector<char>>& matrix, int &mx, vector<vector<int>>& dp)
    // {
    //     // Pruning & Base Case
    //     if(i < 0 || j < 0)
    //     {
    //         return 0;
    //     }

    //     // Cache Check
    //     if(dp[i][j] != -1)
    //     {
    //         return dp[i][j];
    //     }

    //     // Recursive Computations
    //     int x = maxsq(i, j - 1, matrix, mx, dp);
    //     int y = maxsq(i - 1, j, matrix, mx, dp);
    //     int z = maxsq(i - 1, j - 1, matrix, mx, dp);
    //     int ans = 0;

    //     if(matrix[i][j] == '1')
    //     {
    //         ans = 1 + min(x, min(y, z));
    //     }
    //     mx = max(mx, ans);

    //     // Cache (Save) & Return
    //     return dp[i][j] = ans;
    // }

    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // int mx = 0;
        // maxsq(n - 1, m - 1, matrix, mx, dp);
        // return mx * mx;

        // // Tabulation
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // int mx = 0;
        // for(int i = 1; i <= n; i++)
        // {
        //     for(int j = 1; j <= m; j++)
        //     {
        //         int x = dp[i][j - 1];
        //         int y = dp[i - 1][j - 1];
        //         int z = dp[i - 1][j];
        //         int ans = 0;

        //         if(matrix[i - 1][j - 1] == '1')
        //         {
        //             ans = 1 + min(x, min(y, z));
        //         }
        //         mx = max(mx, ans);

        //         dp[i][j] = ans;
        //     }
        // }

        // return mx * mx;

        // Space Optimization
        vector<int> prevrow(m + 1, 0);
        int mx = 0;
        for(int i = 1; i <= n; i++)
        {
            vector<int> currow(m + 1, 0);
            for(int j = 1; j <= m; j++)
            {
                int x = currow[j - 1];
                int y = prevrow[j - 1];
                int z = prevrow[j];
                int ans = 0;

                if(matrix[i - 1][j - 1] == '1')
                {
                    ans = 1 + min(x, min(y, z));
                }
                mx = max(mx, ans);

                currow[j] = ans;
            }
            prevrow = currow;
        }

        return mx * mx;
    }
};