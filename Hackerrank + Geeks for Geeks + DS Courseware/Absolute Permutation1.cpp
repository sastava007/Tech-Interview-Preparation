#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,k,i,c=0,flag=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int arr[n];
        for(i=0;i<n;i++)
            arr[i]=i+1;
        do
        {
            c=0,flag=0;
            for(i=0;i<n;i++)
            if(abs(arr[i]-i-1)==k)
            c++;
            if(c==n)
            {
                for(i=0;i<n;i++)
                    cout<<arr[i]<<" ";
                cout<<endl;
                flag =1;
                break;
            }
        }while(next_permutation(arr,arr+n));
        if(flag==0)
            cout<<"-1"<<endl;
    }
    return 0;
}
