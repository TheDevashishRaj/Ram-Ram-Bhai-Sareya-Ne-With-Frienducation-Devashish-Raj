class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), cnt = 0;
        vector<int> left(n), right(n);
        left[0] = 1;
        right[n - 1] = 1;
        for(int i = 1; i < n; i++)
        {
            if(ratings[i - 1] < ratings[i])
            {
                left[i] = left[i - 1] + 1;
            }
            else
            {
                left[i] = 1;
            }

            if(ratings[n - i - 1] > ratings[n - i])
            {
                right[n - i - 1] = right[n - i] + 1;
            }
            else
            {
                right[n - i - 1] = 1;
            }
        }

        for(int i = 0; i < n; i++)
        {
            cnt += max(left[i], right[i]);
        }

        return cnt;
    }
};