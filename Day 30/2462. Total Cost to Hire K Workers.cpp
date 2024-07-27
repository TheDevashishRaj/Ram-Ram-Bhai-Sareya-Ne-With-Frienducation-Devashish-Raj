class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        multiset<pair<int, int>> lmst, rmst;
        int l = 0, r = costs.size() - 1, f = 0;

        for(int i = 0; i < candidates; i++)
        {
            lmst.insert(make_pair(costs[l], l));
            l++;
        }
        l--;

        for(int i = 0; i < candidates; i++)
        {
            if(l < r)
            {
                rmst.insert(make_pair(costs[r], r));
                r--;
                f = 1;
            }
        }

        if(f)
        {
            r++;
        }

        long long sum = 0;
        while(k)
        {
            if(lmst.empty())
            {
                sum += rmst.begin()->first;
                k--;
                rmst.erase(rmst.begin());
            }
            else if(rmst.empty())
            {
                sum += lmst.begin()->first;
                k--;
                lmst.erase(lmst.begin());
            }
            else
            {
                if(lmst.begin()->first <= rmst.begin()->first)
                {
                    sum += lmst.begin()->first; 
                    k--;
                    l++;
                    lmst.erase(lmst.begin());
                    if(l < r)
                    {
                        lmst.insert(make_pair(costs[l], l)) ;
                    }
                }
                else if(rmst.begin()->first < lmst.begin()->first)
                {
                    sum += rmst.begin()->first; 
                    k--;
                    r--;
                    rmst.erase(rmst.begin());
                    if(l < r)
                    {
                        rmst.insert(make_pair(costs[r] , r));
                    }
                }
            }
        }

        return sum;
    }
};