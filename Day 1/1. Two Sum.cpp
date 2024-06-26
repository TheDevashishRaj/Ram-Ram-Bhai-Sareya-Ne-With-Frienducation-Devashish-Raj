class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> v;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            v.push_back(make_pair(nums[i], i));
        }

        sort(v.begin(), v.end());

        int l = 0, r = n - 1;
        while(l <= r)
        {
            if(v[l].first + v[r].first == target)
            {
                return {v[l].second, v[r].second};
            }
            else if(v[l].first + v[r].first < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }

        return {-1, -1};
    }
};