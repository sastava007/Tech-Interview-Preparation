

class Solution
{
    public:
    //Function to calculate sum of all numbers present in a string.
    int findSum(string str)
    {
    	
    	// Your code here
    	int sum = 0;
    	
    	int n = str.size();
    	int ans = 0;
    	for(int i=0; i<n; i++){
    	    if(str[i] >='0' && str[i] <='9'){
    	        ans = ans * 10 + (str[i] - '0');
    	        
    	    }
    	    
    	    else{
    	        sum += ans;
    	        ans = 0;
    	    }
    	}
    	return sum+ans;
    }
};
