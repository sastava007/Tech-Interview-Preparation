#include<bits/stdc++.h>
using namespace std;

int partition(int *a, int s, int e)
{
    int pivot = a[e];
    int j = s-1;

    int i;
    for(i=s; i<e;i++)
    {
        if(a[i]<pivot)
        {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[j+1], a[e]);     // bring pivot to it's original position
    
    return j+1;
}

int KthSmallestElement(int *a, int s, int e, int k)
{
    if(k>0 && k<=e-s+1)   //if size of array is greater than K
    {   
        int index = partition(a, s, e);

        if(index-s+1 == k)
            return a[index];
        else if(index-s+1>k)
            return KthSmallestElement(a, s, index-1, k);
        else
        {
            return KthSmallestElement(a, index+1, e, k-(index-s+1));
        }
    }
    return INT_MAX;
}

int main()
{
    int arr[] = { 12, 3, 5, 7, 4, 19, 26 };
    
    cout<<KthSmallestElement(arr, 0, 6, 3);

    return 0;
}