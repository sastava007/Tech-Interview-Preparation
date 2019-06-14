#include<bits/stdc++.h>
using namespace std;
main()
{
    int a[]={10, 7, 8, 9, 1, 5};
    int i,j,min,n=6,min_index,temp;
    for(i=0;i<n;i++)
    {
        min=a[i];
        for(j=i;j<n;j++)
        {
            if(a[j]<min)
            {
                min=a[j];
                min_index=j;
            }
        }
        temp=a[i];
        a[i]=min;
        a[min_index]=temp;
    }
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}
