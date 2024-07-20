class Solution {
public:
    bool check(int m, vector<int>& piles, int h)
    {
        long long c = 0;
        for(auto &i: piles)
        {
            c += ceil(((double) i) / ((double) m));
        }

        return c <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end()), ans = r, m;
        while(l <= r)
        {
            m = l + (r - l) / 2;
            if(check(m, piles, h))
            {
                ans = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }

        return ans;
    }
};