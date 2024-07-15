class Solution {
public:
    // // Recursive
    // int profit(int i, int canBuy, int transactions, int k, vector<int>& prices)
    // {
    //     // Pruning & Base Case
    //     if(i >= prices.size() || transactions >= k)
    //     {
    //         return 0;
    //     }

    //     // Recursive Computations
    //     int p = 0;
    //     if(canBuy)
    //     {
    //         int p1 = -prices[i] + profit(i + 1, 0, transactions, k, prices); // Buy Current Stock (Take)

    //         int p2 = profit(i + 1, 1, transactions, k, prices); // Don't Buy Current Stock (Don't Take)
    //         p = max(p1, p2);
    //     }
    //     else
    //     {
    //         int p3 = prices[i] + profit(i + 1, 1, transactions + 1, k, prices); // Sell Current Stock (Take)

    //         int p4 = profit(i + 1, 0, transactions, k, prices); // Don't Sell Current Stock (Don't Take)
    //         p = max(p3, p4);
    //     }

    //     // Return
    //     return p;
    // }

    // // Memoization
    // int profit(int i, int canBuy, int transactions, int k, vector<int>& prices, vector<vector<vector<int>>> &dp)
    // {
    //     // Pruning & Base Case
    //     if(i >= prices.size() || transactions >= k)
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
    //         int p1 = -prices[i] + profit(i + 1, 0, transactions, k, prices, dp); // Buy Current Stock (Take)

    //         int p2 = profit(i + 1, 1, transactions, k, prices, dp); // Don't Buy Current Stock (Don't Take)
    //         p = max(p1, p2);
    //     }
    //     else
    //     {
    //         int p3 = prices[i] + profit(i + 1, 1, transactions + 1, k, prices, dp); // Sell Current Stock (Take)

    //         int p4 = profit(i + 1, 0, transactions, k, prices, dp); // Don't Sell Current Stock (Don't Take)
    //         p = max(p3, p4);
    //     }

    //     return dp[i][canBuy][transactions] = p;
    // }

    int maxProfit(int k, vector<int>& prices) {
        // vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k, -1)));
        // return profit(0, 1, 0, k, prices, dp);

        // // Tabulation with Shifting
        // vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        // for(int i = prices.size() - 1; i >= 0; i--)
        // {
        //     for(int j = 0; j <= 1; j++)
        //     {
        //         for(int l = k - 1; l >= 0; l--)
        //         {
        //             int p = 0;
        //             if(j)
        //             {
        //                 int p1 = -prices[i] + dp[i + 1][0][l]; // Buy Current Stock (Take)

        //                 int p2 = dp[i + 1][1][l]; // Don't Buy Current Stock (Don't Take)
        //                 p = max(p1, p2);
        //             }
        //             else
        //             {
        //                 int p3 = prices[i] + dp[i + 1][1][l + 1]; // Sell Current Stock (Take)

        //                 int p4 = dp[i + 1][0][l]; // Don't Sell Current Stock (Don't Take)
        //                 p = max(p3, p4);
        //             }

        //             dp[i][j][l] = p;
        //         }
        //     }
        // }

        // return dp[0][1][0];

        // Space Optimization with Shifting
        vector<vector<int>> prev(2, vector<int>(k + 1, 0));
        for(int i = prices.size() - 1; i >= 0; i--)
        {
            for(int j = 0; j <= 1; j++)
            {
                for(int l = k - 1; l >= 0; l--)
                {
                    int p = 0;
                    if(j)
                    {
                        int p1 = -prices[i] + prev[0][l]; // Buy Current Stock (Take)

                        int p2 = prev[1][l]; // Don't Buy Current Stock (Don't Take)
                        p = max(p1, p2);
                    }
                    else
                    {
                        int p3 = prices[i] + prev[1][l + 1]; // Sell Current Stock (Take)

                        int p4 = prev[0][l]; // Don't Sell Current Stock (Don't Take)
                        p = max(p3, p4);
                    }

                    prev[j][l] = p;
                }
            }
        }

        return prev[1][0];
    }
};