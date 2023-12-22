// User function template for C++

class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        // code here
        int low=0, high=n-1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(arr[mid] == k){
                return mid;
            }
            
            else if(arr[mid] < k){
                low = mid+1;
            }
            
            else{
                high = high -1;
            }
        }
        
        return -1;
    }
};
