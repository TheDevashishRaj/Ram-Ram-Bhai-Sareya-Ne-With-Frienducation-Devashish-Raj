class Solution {
public:
    // // Memoization - 1 [O(N^2) Time O(N^2) Space]
    // int LIS(int i, int previdx, vector<int>& nums, vector<vector<int>> &dp)
    // {
    //     // Pruning & Base Case
    //     if(i >= nums.size())
    //     {
    //         return 0;
    //     }

    //     // Cache Check
    //     if(dp[i][previdx + 1] != -1)
    //     {
    //         return dp[i][previdx + 1];
    //     }

    //     // Recursive Computations
    //     // Not Take
    //     int x = LIS(i + 1, previdx, nums, dp);

    //     // Take
    //     if(previdx == -1 || nums[i] > nums[previdx])
    //     {
    //         x = max(x, 1 + LIS(i + 1, i, nums, dp));
    //     }

    //     // Cache (Save) and Return
    //     return dp[i][previdx + 1] = x;
    // }

    // // Memoization - 2 [O(N^2) Time O(N) Space]
    // int LIS(int i, vector<int>& nums, vector<int>& dp)
    // {
    //     // Pruning
    //     if(i < 0)
    //     {
    //         return 0;
    //     }

    //     // Base Case

    //     // Cache Check
    //     if(dp[i] != -1)
    //     {
    //         return dp[i];
    //     }

    //     // Recursive Computations
    //     int x = 1;
    //     for(int j = 0; j < i; j++)
    //     {
    //         if(nums[i] > nums[j])
    //         {
    //             x = max(x, LIS(j, nums, dp) + 1);
    //         }
    //     }

    //     // Cache (Save) and Return
    //     return dp[i] = x;
    // }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        // Memo-2 Subcode
        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // return LIS(0, -1, nums, dp);

        // vector<int> dp(n, -1);

        // int mx = 1;
        // for(int i = 0; i < n; i++)
        // {
        //     mx = max(mx, LIS(i, nums, dp));
        // }

        // return mx;

        // // Tabulation of [Memo-1] O(n^2) space (Shift 2nd Dimension to accomodate -1, basically +1 to 2nd coordinate)
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // for(int i = n - 1; i >= 0; i--)
        // {
        //     for(int j = i - 1; j >= -1; j--) // Instead of n - 1 as previous index < i
        //     {
        //         // Not Take
        //         int x = dp[i + 1][j + 1];

        //         // Take
        //         if(j == -1 || nums[i] > nums[j])
        //         {
        //             x = max(x, 1 + dp[i + 1][i + 1]);
        //         }
        //         dp[i][j + 1] = x;
        //     }
        // }
        // return dp[0][-1+1];

        // // Space Optimization of [Memo-1] to a O(n) space
        // vector<int> prev(n + 1, 0);
        // for(int i = n - 1; i >= 0; i--)
        // {
        //     for(int j = i - 1; j >= -1; j--) // Instead of n - 1 as previous index < i
        //     {
        //         // Not Take
        //         int x = prev[j + 1];

        //         // Take
        //         if(j == -1 || nums[i] > nums[j])
        //         {
        //             x = max(x, 1 + prev[i + 1]);
        //         }
        //         prev[j + 1] = x;
        //     }
        // }

        // return prev[-1+1];

        // // Tabulation of [Memo-2] O(n) solution -> Used for tracing back the LIS
        // vector<int> dp(n, 1); // Initially every starting point can be LIS
        // int mx = 1;
        // for(int i = 1; i < n; i++)
        // {
        //     int c = 1;
        //     for(int j = 0; j < i; j++)
        //     {
        //         if(nums[j] < nums[i])
        //         {
        //             c = max(c, 1 + dp[j]);
        //         }
        //     }
        //     dp[i] = c;
        //     mx = max(mx, c);
        // }

        // // For Printing Solution LIS, using maximal dp table formed above.
        // for(int i = 0; i < n; i++)
        // {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;

        // vector<int> ans(mx);
        // int cnt = mx;
        // for(int i = n - 1; i >= 0; i--)
        // {
        //     if(dp[i] == cnt && (cnt == mx || ans[cnt] > nums[i]))
        //     {
        //         ans[cnt - 1] = nums[i];
        //         cnt--;
        //     }
        // }

        // for(int i = 0; i < mx; i++)
        // {
        //     cout << ans[i] << " ";
        // }

        // return mx;

        // Using Binary Search
       vector<int> ans;
       ans.push_back(nums[0]);
       
       for(int i = 1; i < n; i++)
       {
           int lb = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
           if(lb == ans.size())
           {
               ans.push_back(nums[i]);
           }
           else
           {
               ans[lb] = nums[i];
           }
       }
       
       return ans.size();
    }
};