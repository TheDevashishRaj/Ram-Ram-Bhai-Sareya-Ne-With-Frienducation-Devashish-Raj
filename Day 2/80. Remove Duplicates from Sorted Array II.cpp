class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0, n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(j > 1 && nums[j - 2] == nums[i])
            {
                continue;
            }
            else
            {
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
    }
};