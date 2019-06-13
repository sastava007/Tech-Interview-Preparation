#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,i,sum=0,left_sum=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
     {
         cin>>a[i];
         sum+=a[i];

     }
     for(i=0;i<n;i++)
     {

         sum-=a[i];  //here sum become right_sum
         if(left_sum==sum)
         {
             cout<<i;
             break;
         }
        left_sum+=a[i];
     }


}
