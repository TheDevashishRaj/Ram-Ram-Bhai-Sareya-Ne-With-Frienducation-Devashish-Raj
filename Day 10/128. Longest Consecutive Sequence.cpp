class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;

        for(auto &i: nums)
        {
            s.insert(i);
        }

        int mx = 0;

        for(auto &i: nums)
        {
            if(s.find(i - 1) != s.end())
            {
                continue;
            }
            else
            {
                int cur = 1, x = i;
                while(s.find(x + 1) != s.end())
                {
                    cur++;
                    x++;
                }

                mx = max(mx, cur);
            }
        }

        return mx;
    }
};