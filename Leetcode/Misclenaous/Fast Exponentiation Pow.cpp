/* Recursive solution: fast exponentiation */

class Solution {
public:
    double myPow(double x, int n) 
    {
        if(n==0)
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
    double myPow(double x, int n) {
        long p = labs(n);
        double pow = 1;
        while (p) {
            if (p % 2) {
                pow *= x;
            }
            x *= x;
            p /= 2;
        }
        return n > 0 ? pow : 1 / pow;
    }
};