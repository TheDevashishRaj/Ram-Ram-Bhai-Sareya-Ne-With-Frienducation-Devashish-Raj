class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums[0], votes = 0;
        for(auto &i : nums)
        {
            if(votes == 0)
            {
                votes = 1;
                maj = i;
            }
            else if(i == maj)
            {
                votes++;
            }
            else
            {
                votes--;
            }
        }

        return maj;
    }
};