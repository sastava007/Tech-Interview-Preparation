//User function template for C++

class Solution{   
public:
    void reverse(int arr[], int start, int end){
        while(start<end){
            swap(arr[start++], arr[end--]);
        }
    }
    void leftRotate(int arr[], int n, int d) {
        // code here
        d = d % n;
        reverse(arr, 0, d-1);
        reverse(arr, d, n-1);
        reverse(arr, 0, n-1);
        
    }
};
