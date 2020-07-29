/* 
    Using Dynammic Programming:

    Select ith node as root node then the total number of BST around that root will be equal to the product of no. of BST in left part and in right part. 
    TC: O(N^2) and Space: O(N)

*/
class Solution {
public:
    int numTrees(int n) 
    {
        vector<int> dp(n+1, 0);
        dp[0]=1, dp[1]= 1;
        
        for(int i=2; i<=n; i++)
            for(int j=1; j<=i; j++)
                dp[i] += dp[j-1]*dp[i-j];
        
        return dp[n];
    }
};

/* Catalan Number: O(N) TC */

int binomialCoeff(unsigned int n, unsigned int k) 
{ 
    int res = 1; 
  
    // Since C(n, k) = C(n, n-k) 
    if (k > n - k) 
        k = n - k; 
  
    // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1] 
    for (int i = 0; i < k; ++i) 
    { 
        res *= (n - i); 
        res /= (i + 1); 
    }
    return res; 
} 

int catalan(unsigned int n) 
{ 
    unsigned long int c = binomialCoeff(2*n, n);    // Calculate value of 2nCn 
    return c/(n+1);   // return 2nCn/(n+1) 
} 