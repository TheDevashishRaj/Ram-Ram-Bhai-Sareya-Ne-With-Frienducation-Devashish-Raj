class Solution {
public:
    // // Memoization
    // int maxsum(int i, vector<int>& nums, vector<int>& dp)
    // {
    //     // Pruning
    //     if(i < 0 || i >= nums.size())
    //     {
    //         return 0;
    //     }

    //     // Base Case

    //     // Cache-Check
    //     if(dp[i] != -1)
    //     {
    //         return dp[i];
    //     }

    //     // Recursive Computations
    //     int x = max(maxsum(i - 1, nums, dp), maxsum(i - 2, nums, dp) + nums[i]);
        
    //     // Return and Cache
    //     return dp[i] = x;
    // }

    int rob(vector<int>& nums) {
        // // Memoization
        // vector<int> dp(nums.size(), -1);
        // return maxsum(nums.size() - 1, nums, dp);

        // // Tabulation
        // vector<int> dp(nums.size(), 0);
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     int x = nums[i];
        //     if(i > 0)
        //     {
        //         x = max(x, dp[i - 1]);
        //     }
        //     if(i > 1)
        //     {
        //         x = max(x, dp[i - 2] + nums[i]);
        //     }

        //     dp[i] = x;
        // }

        // return dp[nums.size() - 1];

        // Space Optimization
        int prev = nums[0], prev2 = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            int x = max(prev, prev2 + nums[i]);
            
            prev2 = prev;
            prev = x;
        }

        return prev;
    }
};