//------------------------Time complexity : O(n)----------------//
//------------------------Auxiliary Space : O(n)----------------//
//------------------RIGHT SIDE ROTATION------------------------//

#include<bits/stdc++.h>
using namespace std;
main()
{
    int t,n,i,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int a[n],b[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            b[(i+k)%n]=a[i];
        }
        for(i=0;i<n;i++)
        cout<<b[i]<<" ";
        cout<<endl;
    }
}
//----------------A SHORT TRICK-------------------//

 #1 Reverse the first k elements, i.e from index [0 to k-1]

 #2 And then reverse the remaining n-k elements.

 #3 Finally revserse the whole array.

 #4 And for this you can use reverse(first,last) STL function of C++

