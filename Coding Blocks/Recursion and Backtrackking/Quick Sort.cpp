#include<bits/stdc++.h>
using namespace std;

/*
    * Choose one element as pivot element
    * Make a partition in array with two regions one which contains element smaller than pivot and other which are greater
    * Finally place the pivot at its appropriate position
    * And call quicksort on left and right region of pivot element
*/

void shuffle(int *a, int s, int e)
{
    // to randomly shuffle all the elements of array on each run
    srand(time(NULL));
    for(int i=e;i>0;i--)
    {
        int j=rand()%i;
        swap(a[i],a[j]);
    }
}

int partition(int *a, int s, int e)
{
    int pivot=a[e];
    int i=s-1;
    int j=s;
    for(;j<e;j++)
    if(a[j]<=pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    // bring pivot element back to its original position
    swap(a[i+1],a[e]);
    return i+1;
}

void quicksort(int *a, int s, int e)
{
    if(s>=e)
        return;

    int p=partition(a,s,e);
    quicksort(a,s,p-1);
    quicksort(a,p+1,e);


}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a[]={1,2,3,4,5,6,7};
    shuffle(a,0,6);
    for(int i=0;i<=6;i++)
        cout<<a[i]<<" ";
    cout<<"\n";

    quicksort(a,0,6);
    for(int i=0;i<=6;i++)
        cout<<a[i]<<" ";
}

