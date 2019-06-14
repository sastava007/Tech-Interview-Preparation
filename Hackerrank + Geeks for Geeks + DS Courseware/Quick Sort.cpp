#include<bits/stdc++.h>
using namespace std;
void quick_sort(int a[],int first,int last)
{
    int low=first;
    int high=last;
    int pi=a[(first+last)/2];
    do
    {
        while(a[low]<pi)    //change sign for descending
            low++;
        while(a[high]>pi)   //change sign for descending
            high--;
        if(low<=high)
        {
            int temp=a[low];
            a[low++]=a[high];
            a[high--]=temp;
        }
    }while(low<=high);
    if(first<high)
        quick_sort(a,first,high);
    if(low<last)
        quick_sort(a,low,last);
}
main()
{
    int a[]={10, 7, 8, 9, 1, 5};
    int first=0,last=5;
    quick_sort(a,first,last);
    for(int i=0;i<6;i++)
        cout<<a[i]<<" ";
}
