//User function template for C++

class Solution{   
public:
    int countZeroes(int arr[], int n) {
        // code here
        int low = 0, high = n-1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(arr[mid] == 1){
                low = mid + 1;
            }
            
            else{
                high = mid -1;
            }
        }
        
        return n - 1 - high;
    }
};
