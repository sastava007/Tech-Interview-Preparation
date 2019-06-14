#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,i,j,key;
    cout<<"Enter size of array"<<endl;
    cin>>n;                              //to take input size of array from the user
    int arr[n];
    cout<<"Enter elements of array"<<endl;
    for(i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter element to delete"<<endl;
    cin>>key;
    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            for(j=i;j<n-1;j++)
                arr[j]=arr[j+1];
            n--;                    //to decrease the size of array
        }
    }
    cout<<"Resultant array is"<<endl;      //print the final resultant array
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
