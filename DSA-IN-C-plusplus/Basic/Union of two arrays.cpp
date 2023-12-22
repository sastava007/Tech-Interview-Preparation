//User function template in C++

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        //code here
        int k = m+n;
        
        int count = 0;
        int idx = 0;
        int arr[n+m];
        
        for(int i=0; i<n; i++){
            arr[idx] = a[i];
            idx++;
        }
        
        for(int i=0; i<m; i++){
            arr[idx] = b[i];
            idx++;
        }
        
        sort(arr, arr+k);
        for(int i=0; i<k; i++){
            if(arr[i] == arr[i+1]){
                count++;
            }
        }
        
        return k-count;
    }
};
