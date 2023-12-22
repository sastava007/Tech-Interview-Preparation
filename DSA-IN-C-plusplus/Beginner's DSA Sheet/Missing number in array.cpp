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
