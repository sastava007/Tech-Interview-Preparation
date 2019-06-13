#include<bits/stdc++.h>
using namespace std;
main()
{
   int n,i,j,k;
    cout<<"Enter size of array"<<endl;
    cin>>n;            //input size of array from user
    int arr[n];
    cout<<"Enter elements of array"<<endl;
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
            if(arr[i]==arr[j])
        {
            for(k=j;k<n-1;k++)
                arr[k]=arr[k+1];
            n--;
        }
    }
    cout<<"Resultant array is:"<<endl;      //array after deleting all the duplicate elements
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
