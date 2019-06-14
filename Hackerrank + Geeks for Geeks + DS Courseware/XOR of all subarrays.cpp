/*
    Find XOR of all subarrays XOR
    Note: Subarrays means contigious subarrays and there are n(n+1)/2 subarrays having array of size n
    Geeks for Geeks: https://www.geeksforgeeks.org/xor-subarray-xors/
*/

#include<bits/stdc++.h>
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    int xore=0;
    for(i=0;i<n;i++)
    {
        int temp=(n-i)*(i+1);
        if(temp&1)
            xore^=a[i];
    }
    cout<<xore;
}
