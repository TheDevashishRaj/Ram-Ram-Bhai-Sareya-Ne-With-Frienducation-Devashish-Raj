class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0, mxsum = nums[0], mnsum = nums[0], cmx = 0, cmn = 0, n = nums.size();
        for(int i = 0; i < n; i++)
        {
            cmx = max(cmx + nums[i], nums[i]);
            mxsum = max(mxsum, cmx);
            cmn = min(cmn + nums[i], nums[i]);
            mnsum = min(mnsum, cmn);
            sum += nums[i];
        }

        return mxsum > 0 ? max(mxsum, sum - mnsum) : mxsum;
    }
};