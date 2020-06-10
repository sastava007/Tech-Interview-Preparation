/*  */

class Solution {
public:
    int myAtoi(string str) 
    {
        if(str.length()==0)
            return 0;
        
        int i=0, sign=1;
        
        while(str[i]==' ' && i<str.length())
            i++;
        if(i==str.length())
            return 0;
    
        if(str[i]=='+' || str[i]=='-')
        {
            sign = str[i]=='+'?1:-1;
            i++;
        }
        
        long result = 0;
        while(i<str.length() && isdigit(str[i]))
        {
            result = result*10+(str[i++]-'0');
            if(result*sign>INT_MAX)
                return INT_MAX;
            if(result*sign<INT_MIN)
                return INT_MIN;
            
        }
        
        return sign*result;
    }
};

/* If we can't use long then use this for overflow check */
if(Integer.MAX_VALUE / 10 < total || Integer.MAX_VALUE / 10 == total && Integer.MAX_VALUE % 10 < digit)
                return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;