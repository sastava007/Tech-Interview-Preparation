/* Using DP memoizations, similar to Fibonaaci numbers */

class Solution {
public:
    int numDecodings(string s) 
    {
        if(s.length()==0 || s[0]=='0')  //becz we can't decode 0 to any alphabet, the mapping lies in b/w [1-26]
            return 0;
        
        int n = s.length();
        vector<int> dp(n+1);
        
        dp[0]  = 1;
        dp[1] = s[1]!='0' ? 1:0;
        
        for(int i = 2; i<=n; i++)
        {
            int first = s[i-1]-'0';
            int second = stoi(s.substr(i-2, 2));
            
            if(first>=1 && first<=9)
                dp[i]+=dp[i-1];
            
            if(second>=10 && second<=26)
                dp[i]+=dp[i-2];
        }
        
        return dp[n];
    }
};

/* Modifying memoization for constant space */
class Solution {
public:
    int numDecodings(string s) 
    {
        if(s.length()==0 || s[0]=='0')  //if empty string or if first digit is 0 then return 0
            return 0;
        
        int n = s.length();
        
        if(n == 1)  //if only 1 digit, and which isn't zero then return 1
            return 1;
        
        int pre1 = 1, pre2 =1, cur;
        
        for(int i = 2; i<=n; i++)
        {
            int first = s[i-1]-'0';                     // if we pick first digit and call of other remaining 12345 => [1][2345]
            int second = stoi(s.substr(i-2, 2));        // when we select first 2 elements and are valid 12345 => [12][345]
            
            cur = 0;
            
            if(first>=1 && first<=9)
                cur += pre1;
            
            if(second>=10 && second<=26)
                cur += pre2;
            
            pre2 = pre1;
            pre1 = cur;
        }
        
        return cur;
    }
};