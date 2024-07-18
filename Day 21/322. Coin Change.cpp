#define INF (int) (1e9)
class Solution {
public:
    // // Memoization
    // int numcoins(int i, int sum, vector<int>& coins, vector<vector<int>> &dp)
    // {
    //     // Pruning
    //     if(i > coins.size() || sum < 0)
    //     {
    //         return INF;
    //     }

    //     // Base Case
    //     if(i == coins.size())
    //     {
    //         if(sum == 0)
    //         {
    //             return 0;
    //         }

    //         return INF;
    //     }

    //     // Cache Check
    //     if(dp[i][sum] != -1)
    //     {
    //         return dp[i][sum];
    //     }

    //     // Recursive Computations
    //     // Not Take (Move to next state of i)
    //     int x = numcoins(i + 1, sum, coins, dp);

    //     // Take (And can take ith coin again. So, stay at same state of i)
    //     int y = 1 + numcoins(i, sum - coins[i], coins, dp);
    //     // Cache (Save) & Return
    //     return dp[i][sum] = min(x, y);
    // }

    int coinChange(vector<int>& coins, int amount) {
        // int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        // int mn = numcoins(0, amount, coins, dp);
        // if(mn == INF)
        // {
        //     return -1;
        // }

        // return mn;

        // // Tabulation
        // int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        // for(int i = n - 1; i >= 0; i--)
        // {
        //     for(int j = 0; j <= amount; j++)
        //     {
        //         if(i == n - 1)
        //         {
        //             int c = 0;
        //             if(j % coins[i] == 0)
        //             {
        //                 c = j / coins[i];
        //             }
        //             else
        //             {
        //                 c = INF;
        //             }

        //             dp[i][j] = c;
        //             continue;
        //         }

        //         int x = dp[i + 1][j], y = INF;
        //         if(j - coins[i] >= 0)
        //         {
        //             y = 1 + dp[i][j - coins[i]];
        //         }

        //         dp[i][j] = min(x, y);
        //     }
        // }

        // if(dp[0][amount] == 1e9)
        // {
        //     return -1;
        // }

        // return dp[0][amount];

        // Space Optimization
        int n = coins.size();
        vector<int> prevrow(amount + 1, -1);
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = 0; j <= amount; j++)
            {
                if(i == n - 1)
                {
                    int c = INF;
                    if(j % coins[i] == 0)
                    {
                        c = j / coins[i];
                    }

                    prevrow[j] = c;
                    continue;
                }

                int x = prevrow[j], y = INF;
                if(j - coins[i] >= 0)
                {
                    y = 1 + prevrow[j - coins[i]];
                }

                prevrow[j] = min(x, y);
            }
        }

        if(prevrow[amount] == 1e9)
        {
            return -1;
        }

        return prevrow[amount];
    }
};