//User function template for C++
class Solution{
public:

int findMaximum(int arr[], int n) {
    // code here
    int mid = n/2;
    if(arr[n-1]<arr[n-2]){
        while(1){
            if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1])
                return arr[mid];
            else if(arr[mid]<arr[mid-1])
                mid--;
            else 
                mid++;
        }
    }else{
        return arr[n-1];
    }
}
};
