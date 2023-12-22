//User function Template for C++

class Solution
{
   public:
    int findSum(int A[], int N)
    {
    	//code here.
    	int min = INT_MAX;
    	int max = INT_MIN;
    	
    	for(int i=0; i<N; i++){
    	    if(A[i] < min){
    	        min = A[i];
    	    }
    	}
    	
    	for(int i=0; i<N; i++){
    	    if(A[i] > max){
    	        max = A[i];
    	    }
    	}
    	
    	return max + min;
    }

};
