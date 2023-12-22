class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        
        long long ans = 0;
        
        for(int i=1 ; i<= N ; i++){
            
            int noOfOccurenceOfI = (N/i);
            
            ans += (1ll * noOfOccurenceOfI * i);
            
        }
        
        return ans;
        
    }
};
