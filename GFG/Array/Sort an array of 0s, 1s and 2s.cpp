/* 
    https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0
    Approach: Use two pointers, i and j. Swap the values such that all 0s are at left end and 2s at last which will automatically place the remaining 1s in the middle 
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,ele,i,j=0,size;
        cin>>n;
        size=n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        i=0;
        while(i<n)
        {
            if(a[i]==0)
            swap(a[i++],a[j++]);
            else if(a[i]==2)
            swap(a[i],a[--n]);
            else
            i++;
        }
        for(i=0;i<size;i++)
        cout<<a[i]<<" ";
        cout<<"\n";
    }
    return 0;
}