#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void sort(int i,int n,int *a)
{
    for(int i=i;i<n;i++)
        for(int j=0;j<n-1;j++)
        if(a[j]>a[j+1])
        swap(&a[j],&a[j+1]);
}
main()
{
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=n-1;i>0;i--)
        if(a[i]>a[i-1])
            break;
    if(i==0)
        {
            cout<<"NOT POssible";
            exit(1);
        }
         if(i==n-1)
            swap(&a[n-1],&a[n-2]);
        else
        {
            swap(&a[i-1],&a[n-1]);
            sort(a+i,a+n);
        }
        for(i=0;i<n;i++)
            cout<<a[i]<<" ";

}
