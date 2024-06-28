class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pf = 0, n = prices.size();
        for(int i = 0; i < n - 1; i++)
        {
            if(prices[i + 1] - prices[i] > 0)
            {
                pf += prices[i + 1] - prices[i];
            }
        }

        return pf;
    }
};