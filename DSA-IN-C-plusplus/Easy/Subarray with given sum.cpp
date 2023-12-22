class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        long long i=0,  sum = 0;
        for(int j=0; j<n; j++){
            sum += arr[j];
            while(sum > s && i<j){
                sum -= arr[i++];
            }
            
            if(sum ==  s){
                return {i+1, j+1};
            }
        }
        
        return {-1};
    }
};
