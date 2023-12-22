class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int>& arr){
        
        // Your code here
        for(int i=0; i<n; i+=2){
            if(i+1<n){
                swap(arr[i], arr[i+1]);
            }
        }
        
    }
};
