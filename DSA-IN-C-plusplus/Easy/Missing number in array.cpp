// User function template for C++

class Solution{
  public:
     int MissingNumber(vector<int>& array, int n) {
       // Your code goes here
       
       sort(array.begin(),array.end());
       for(int i=0; i<n; i++)
       {
           if(array[i]!=i+1)
               return (i+1);
       }
   }
};

// Solution 2

// User function template for C++

class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        // Your code goes here
        int reqSum = (n*(n+1))/2;
        int curSum = 0;
        
        for(int i=0; i<n-1; i++){
            curSum += array[i];
        }
        
        return reqSum-curSum;
    }
};
