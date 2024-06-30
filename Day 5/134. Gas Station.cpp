class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumgas = 0, sumcost = 0;
        for(auto &i:gas)
        {
            sumgas += i;
        }

        for(auto &i: cost)
        {
            sumcost += i;
        }

        if(sumcost > sumgas)
        {
            return -1;
        }

        int s = 0, sum = 0, n = gas.size();
        for(int i = 0; i < n; i++)
        {
            sum += (gas[i] - cost[i]);
            if(sum < 0)
            {
                s = i + 1;
                sum = 0;
            }
        }

        return s;
    }
};