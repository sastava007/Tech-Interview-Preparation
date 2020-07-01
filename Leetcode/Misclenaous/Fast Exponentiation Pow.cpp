/*  Divide & Conquer: fast exponentiation 
    TC: O(logN) and Space: O(logN) due to recursive call stack
*/

class Solution {
public:
    double myPow(double x, int n) 
    {
        if(n==0)    //base case
            return 1;
        
        double temp = myPow(x,n/2);
        temp = temp*temp;
        if(n&1) //if odd power
        {
            if(n<0)
                return (1/x*temp);
            else
                return (x*temp);
        }
        return temp;
    }
};


/* Iterative solution */

class Solution {
public:
    double myPow(double x, int n) 
    {
        n = abs(n);
        double pow = 1;
        while (n) 
        {
            if (n&1) 
            {
                pow *= x;
            }
            
            x *= x;
            n /= 2;
        }
        return n > 0 ? pow : 1 / pow;
    }
};