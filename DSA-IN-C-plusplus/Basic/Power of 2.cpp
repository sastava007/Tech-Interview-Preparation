//User function Template for C++

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here  
        
        if(n==1) return true;
        
        if(n <= 0 || n%2 != 0) return false;
        
        return isPowerofTwo(n/2);
        
    }
};


// Solution 2

//User function Template for C++

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here  
        
        if(n==0) return false;
        
        if((n&(n-1)) == 0) return true;
        
        return false;
        
    }
};
