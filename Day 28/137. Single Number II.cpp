class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int o = 0, t = 0;
        for(auto &i: nums)
        {
            o ^= (i & ~t);
            t ^= (i & ~o);
        }

        return o;
    }
};