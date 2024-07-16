class Solution {
public:
    string longestPalindrome(string s) {
        // "Substring" => Keep in mind
        int n = s.size(), mx = 1, beg = 0, end = 0;
        if(n <= 1)
        {
            return s;
        }

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int i = 0; i < n; i++)
        {
            dp[i][i] = true;
            for(int j = 0; j < n; j++)
            {
                if(s[j] == s[i] && (i <= j + 2 || dp[j + 1][i - 1]))
                {
                    dp[j][i] = true;
                    if (i - j + 1 > mx) {
                        mx = i - j + 1;
                        beg = j;
                        end = i;
                    }
                }
            }
        }

        return s.substr(beg, end - beg + 1);
    }
};