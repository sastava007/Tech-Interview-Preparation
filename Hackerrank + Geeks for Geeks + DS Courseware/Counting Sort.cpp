/*
    https://www.geeksforgeeks.org/counting-sort/
    Time Complexity: O(N+K), where K is range of values of array
    Space complexity: O(K) 
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    //here we are using min & max element for dealing with negative numbers and build the range.
    int n,i,minE=INT_MAX,maxE=INT_MIN;
    cin>>n;
    int a[n], out[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        minE = min(minE, a[i]);
        maxE = max(maxE, a[i]);
    } 
    int range = maxE-minE+1;
    int count[range]={0};
    for(i=0;i<n;i++)
    count[a[i]-minE]++;

    for(i=1;i<range;i++)
    {
        count[i]+=count[i-1];
    }

    //produce the output array
    for(i=0;i<n;i++)
    {
        out[count[a[i]-minE]-1]=a[i];
        count[a[i]-minE]--;
    }
    for(i=0;i<n;i++)
    cout<<out[i]<<" ";
    
    return 0;
}