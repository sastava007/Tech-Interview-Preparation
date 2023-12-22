//User function template for C++

class Solution{
public:
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long>& arr, int n, int k){
       // code here
       for(int i = 0; i<n; i+=k){
           int s = i;
           int e = min(i+k-1, n-1);
           while(s < e){
               int temp = arr[s];
               arr[s] = arr[e];
               arr[e] = temp;
               s++;
               e--;
           }
       }
   }

 
};
