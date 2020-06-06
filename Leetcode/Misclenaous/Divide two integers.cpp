/*  The no. are in range int [-2^31 - 2^31-1], so upon peformning  any bitwise shifting if can get overflow, so that's why doing all precautions
    Time Complexity: O(logn)
*/

class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        if(divisor == 0)
            return INT_MAX;
        if(divisor == INT_MIN)
            return (dividend==INT_MIN ? 1:0);
        
        int quotient = 0;
        if(dividend == INT_MIN)
        {
            if(divisor == -1)
                return INT_MAX;
            if(divisor == 1)
                return INT_MIN;
            
            dividend += abs(divisor);
            quotient = 1;
        }
        
        bool isNegative = (dividend<0) ^ (divisor<0);
        
        int dvnd = fabs(dividend);
        int dvsr = fabs(divisor);
        
        while(dvnd >= dvsr)
        {
            int temp = dvsr, m = 1;
            while((dvnd >= (temp<<1)) && (temp<<1 >0))
            {
                temp <<= 1;
                m <<= 1;
            }
            dvnd -= temp;
            quotient += m;
        }
        
        if(isNegative)
            return -quotient;
        else
            return quotient;
         
    }
};