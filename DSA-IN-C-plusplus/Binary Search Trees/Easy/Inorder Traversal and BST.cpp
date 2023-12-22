class Solution{
    public:
    int isRepresentingBST(int arr[], int N)
    {
        // code here
        for(int i=0; i<N-1; i++){
            if(arr[i+1]<arr[i]){
                return 0;
            }
            
        }
        
        return 1;
    }
};

