class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0, n = nums.size();

        for(int i = 0; i < n; i++)
        {
            if(nums[i] != nums[j])
            {
                j++;
                nums[j] = nums[i];
            }
        }

        return j + 1;
    }
};