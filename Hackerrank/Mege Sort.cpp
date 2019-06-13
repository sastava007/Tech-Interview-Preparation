#include<iostream>
using namespace std;
void merge(int *a,int s,int e)
{
    int mid=(s+e)/2;
    int i=s;
    int j=mid+1;
    int k=s;
    int result[e-s+1];
    int c=0;

    while(i<=mid && j<=e)
    {
        if(a[i]<a[j])
            result[k++]=a[i++];
        else
        {
          result[k++]=a[j++];

        }

    }
    // IF ONE OF THE ARRAY GET EXHAUSTED THEN COPY ALL THE REMAINING ELEMENTS
    while(i<=mid)
        result[k++]=a[i++];
    while(j<=e)
    result[k++]=a[j++];
    for(int i=s;i<=e;i++)
        a[i]=result[i];

}
void merge_sort(int a[],int s,int e)
{
    if(s>=e)
        return;

    //1. DIVIDE
        int mid=(s+e)/2;

    //2. RECURSIVELY SORT
        merge_sort(a,s,mid);
        merge_sort(a,mid+1,e);

    //3. COMBINE ALL SORTED PARTS
        merge(a,s,e);
}
main()
{
    int a[]={ 1, 20, 6, 4, 5 };
    merge_sort(a,0,4);
//    for(int i=0;i<6;i++)
//        cout<<a[i]<<" ";
        cout<<c;
}
