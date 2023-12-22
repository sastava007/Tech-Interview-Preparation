class Solution{
  public:
    int thirdLargest(int a[], int n)
    {
         //Your code here
         int first = INT_MIN;
         int second = INT_MIN;
         int third = INT_MIN;
         
         for(int i=0; i<n; i++){
             if(a[i]>first){
                 third = second;
                 second = first;
                 first = a[i];
             }
             
             else if(a[i] > second && a[i] <= first){
                 third = second;
                 second = a[i];
             }
             
             else if(a[i] > third && a[i] <= second){
                 third = a[i];
             }
         }
         
         return third;
    }

};
