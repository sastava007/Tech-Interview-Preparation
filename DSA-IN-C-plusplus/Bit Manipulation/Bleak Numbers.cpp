class Solution
{
public:
	int is_bleak(int n)
	{
	    // Code here.
	    for(int i = n -1; i>=n - ceil(log2(n)); i--){
	        if(i +__builtin_popcount(i) == n) return 0;
	    }
	    
	    return 1;
	}
};
