class Solution {
public:
    // // Recursion
    // int profit(int i, int canBuy, int transactions, vector<int>& prices)
    // {
    //     // Pruning & Base Case
    //     if(i >= prices.size() || transactions >= 2)
    //     {
    //         return 0;
    //     }

    //     // Recursive Computations
    //     int p = 0;
    //     if(canBuy)
    //     {
    //         int p1 = -prices[i] + profit(i + 1, 0, transactions, prices); // Buy Current Stock (Take)
    //         int p2 = profit(i + 1, 1, transactions, prices); // Don't Buy Current Stock (Not Take)
    //         p = max(p1, p2);
    //     }
    //     else
    //     {
    //         int p3 = prices[i] + profit(i + 1, 1, transactions + 1, prices); // Sell Current Stock (Take)
    //         int p4 = profit(i + 1, 0, transactions, prices); // Don't Sell Current Stock (Not Take)
    //         p = max(p3, p4);
    //     }


    //     // Return
    //     return p;
    // }

    // // Memoization
    // int profit(int i, int canBuy, int transactions, vector<int>& prices, vector<vector<vector<int>>> &dp)
    // {
    //     // Pruning & Base Case
    //     if(i >= prices.size() || transactions >= 2)
    //     {
    //         return 0;
    //     }

    //     // Cache Check
    //     if(dp[i][canBuy][transactions] != -1)
    //     {
    //         return dp[i][canBuy][transactions];
    //     }

    //     // Recursive Computations
    //     int p = 0;
    //     if(canBuy)
    //     {
    //         int p1 = -prices[i] + profit(i + 1, 0, transactions, prices, dp); // Buy Current Stock (Take)
    //         int p2 = profit(i + 1, 1, transactions, prices, dp); // Don't Buy Current Stock (Not Take)
    //         p = max(p1, p2);
    //     }
    //     else
    //     {
    //         int p3 = prices[i] + profit(i + 1, 1, transactions + 1, prices, dp); // Sell Current Stock (Take)
    //         int p4 = profit(i + 1, 0, transactions, prices, dp); // Don't Sell Current Stock (Not Take)
    //         p = max(p3, p4);
    //     }


    //     // Cache (Save) & Return
    //     return dp[i][canBuy][transactions] = p;
    // }

    int maxProfit(vector<int>& prices) {
        // vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(2, -1)));
        // return profit(0, 1, 0, prices, dp);

        // // Tabulation with Shifting index (Basically +1 in D1 and D3 dimensions)
        // vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        // for(int i = prices.size() - 1; i >= 0; i--)
        // {
        //     for(int j = 0; j <= 1; j++)
        //     {
        //         for(int k = 1; k >= 0; k--)
        //         {
        //             int p = 0;
        //             if(j)
        //             {
        //                 int p1 = -prices[i] + dp[i + 1][0][k]; // Buy Current Stock (Take)
        //                 int p2 = dp[i + 1][1][k]; // Don't Buy Current Stock (Not Take)
        //                 p = max(p1, p2);
        //             }
        //             else
        //             {
        //                 int p3 = prices[i] + dp[i + 1][1][k + 1]; // Sell Current Stock (Take)
        //                 int p4 = dp[i + 1][0][k]; // Don't Sell Current Stock (Not Take)
        //                 p = max(p3, p4);
        //             }

        //             dp[i][j][k] = p;
        //         }
        //     }
        // }

        // return dp[0][1][0];

        // Space Optimization [O(1) space] with Shifting index (Basically +1 in D1 and D3 dimensions)
        vector<vector<int>> prev(2, vector<int>(3, 0));
        for(int i = prices.size() - 1; i >= 0; i--)
        {
            for(int j = 0; j <= 1; j++)
            {
                for(int k = 1; k >= 0; k--)
                {
                    int p = 0;
                    if(j)
                    {
                        int p1 = -prices[i] + prev[0][k]; // Buy Current Stock (Take)
                        int p2 = prev[1][k]; // Don't Buy Current Stock (Not Take)
                        p = max(p1, p2);
                    }
                    else
                    {
                        int p3 = prices[i] + prev[1][k + 1]; // Sell Current Stock (Take)
                        int p4 = prev[0][k]; // Don't Sell Current Stock (Not Take)
                        p = max(p3, p4);
                    }

                    prev[j][k] = p;
                }
            }
        }

        return prev[1][0];
    }
};