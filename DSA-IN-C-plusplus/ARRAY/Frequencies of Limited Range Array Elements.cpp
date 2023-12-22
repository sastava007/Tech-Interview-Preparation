class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        // code here
        for(int i=0; i<N; i++){
            if((arr[i]-1)%(P+1)<N){
                arr[(arr[i]-1) % (P+1)] += (P+1);
            }
        }
        
        for(int i=0; i<N; i++){
            arr[i] /= (P+1);
        }
    }
};
