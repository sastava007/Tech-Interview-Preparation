class Solution
{
    public:
    long long power(long long x,int y, int p)
    {
        long long res = 1; // Initialize result
        while (y > 0)
        {
            // If y is odd, multiply x with result
            if (y & 1)
                res = (res * x) % p;
            // y must be even now
            y = y >> 1; // y = y/2
            x = (x * x) % p;
        }
        return res;
    }
 
    // Returns n^(-1) mod p
    long long modInverse(long long n,int p)
    {
        return power(n, p - 2, p);
    }
    long long  numberOfPaths(int M, int N)
    {
        long long path = 1,mod=1e9+7;
        for (long long i = N; i < (M + N - 1); i++) {
            path = (path*i)%mod;
            long long inv=modInverse(i-N+1,mod);
            path = (path*inv)%mod;
        }
        return path;
    }
};
