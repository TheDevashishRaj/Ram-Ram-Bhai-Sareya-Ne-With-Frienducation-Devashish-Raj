class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(), potions.end());

        for(int i = 0; i < spells.size(); i++)
        {
            int c = 0, l = 0, r = potions.size();
            while(l < r)
            {
                int m = (l + r) / 2;

                if(potions[m] * 1ll * spells[i] >= success)
                {
                    r = m;
                }
                else
                {
                    l = m + 1;
                }
            }
            c += potions.size() - r;
            ans.push_back(c);
        }
        
        return ans;
    }
};