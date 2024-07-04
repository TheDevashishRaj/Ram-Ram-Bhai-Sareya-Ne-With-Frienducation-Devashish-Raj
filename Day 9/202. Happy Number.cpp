class Solution {
public:
    bool isHappy(int n) {
        if(n == 1)
        {
            return true;
        }

        if(n <= 4)
        {
            return false;
        }

        int x = 0, temp = n;
        while(temp)
        {
            x += (temp % 10) * (temp % 10);
            temp /= 10;
        }

        return isHappy(x);
    }
};