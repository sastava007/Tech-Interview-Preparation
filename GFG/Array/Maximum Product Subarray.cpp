/*
    This is similar to maximum sum subarray solved using kadane's Algorithm
    Here we have to also consider -ve elements, and hence need to maintain maxVal and minVal
    Keep two variables minVal and maxVal which represents the minimum and maximum product value till the ith index of the array
    if the ith element of the array is negative that means now the values of minVal and maxVal will be swapped as value of maxVal will 
    become minimum by multiplying it with a negative number.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        ll a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        ll maxVal = a[0], minVal=a[0], ans=a[0];
        for(i=1;i<n;i++)
        {
            if(a[i]<0)
            swap(maxVal, minVal);
            maxVal=max(a[i], a[i]*maxVal);
            minVal=min(a[i], a[i]*minVal);
            ans = max(ans, maxVal);
        }
        cout<<ans<<"\n";
    }
    return 0;
}