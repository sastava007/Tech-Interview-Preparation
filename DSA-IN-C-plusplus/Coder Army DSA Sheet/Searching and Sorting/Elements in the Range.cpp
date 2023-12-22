class Solution{
	public:
    	bool check_elements(int arr[], int n, int A, int B){
    		// Your code goes here
    		sort(arr, arr+n);
    		
    		for(int i=0; i<n; i++){
    		    if(arr[i] == A) A++;
    		    
    		}
    		
    		if(A > B) return true;
    		
    		else return false;
    	}

};

// Using set

class Solution{
	
	
	public:
    	bool check_elements(int arr[], int n, int A, int B){
    		// Your code goes here
    		set<int>s;
    		for(int i = 0; i<n; i++){
    		    s.insert(arr[i]);
    		}
    		
    		for(int i=A; i<=B; i++){
    		    auto it=s.find(i);
    		    
    		    if(it == s.end()){
    		        return false;
    		    }
    		}
    		
    		return true;
    	}
};
	
	
