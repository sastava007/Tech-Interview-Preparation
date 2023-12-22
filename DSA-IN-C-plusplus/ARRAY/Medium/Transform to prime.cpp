#define ll long long
class Solution
{
    public:
    bool isPrime(int n)
    {
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            return 0;
        }
        return 1;
    }
    
    int minNumber(int arr[],int N)
    {
        ll sum=0;
        for(int i=0;i<N;i++)
        sum+=arr[i];
        
        ll temp=sum;
        while(1)
        {
            if(isPrime(temp))
            return temp-sum;
            else
            temp++;
        }
        
        return 0;
    }
};
