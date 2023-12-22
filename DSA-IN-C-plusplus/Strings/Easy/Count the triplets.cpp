//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    // Your code goes here
	    int count = 0;
	    unordered_set<int>st(arr, arr+n);
	    
	    for(int i=0; i<n; i++){
	        for(int j=i+1; j<n; j++){
	            if(st.count(arr[i]+arr[j])){
	                count++;
	            }
	        }
	    }
	    
	    return count;
	}
};
