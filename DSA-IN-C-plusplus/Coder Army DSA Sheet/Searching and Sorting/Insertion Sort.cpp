class Solution
{
    public:
    void insert(int arr[], int n)
    {
        //code here
        int i, j, x;
        
        for(int i=1; i<n; i++){
            j=i-1;
            x=arr[i];
            
            while(j>-1 && arr[j]>x){
                arr[j+1] = arr[j];
                j--;
            }
            
            arr[j+1] = x;
        }
        
    }
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        //code here
        insert(arr, n);
    }
};
