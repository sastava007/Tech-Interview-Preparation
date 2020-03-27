/*
    https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1
    This approach works becz all the elements are b/w (0 to n-1), so evenafter adding n to it it wil be (2n-1)/n which is 1

*/
void printDuplicates(int a[], int n) {
    int c=1;
    for(int i=0; i<n; ++i)
    {
        // Here we are moduling it with n, to get it's original value of element that has been lost after adding n so many times
        int ind = a[i] % n;
        a[ind] += n;
    }
    
    for(int i=0; i<n; ++i){
        // a[i]/n will give me frequency of element
        if(a[i]/n > 1){
            cout<<i<<" ";
            c =0;
        }
    }
    
    if(c) cout<<"-1";
}