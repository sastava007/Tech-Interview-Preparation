//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    int count = 0;
	    
	    for(int i=0; i<n; i++){
	        if(arr[i] != 0){
	            arr[count++] = arr[i];
	        }
	    }
	    
	    while(count < n){
	        arr[count++] = 0;
	    }
	}
};
