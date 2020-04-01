/*
    Bit Play:  Bit diference is 1 only when one of the bit is 1, so if we consider that all the elements are 32 bit number then we can find element which has set bit. 
    Let count represnts the no of of such elements which has set bits at position i then (n-count) will be those elements which as unset bits, and to get bit difference(i.e XOR) as 1
    we have to map any of the setbit elements to unset one, which will contribute 1 to difference sum. So we have now count*(n-count) as differnce sum and multiply it with 2 for repition.

    # This is a also known as hamming distance b/w two integers.(i.e no of different bits)
    https://practice.geeksforgeeks.org/problems/sum-of-bit-differences/0
    https://leetcode.com/problems/total-hamming-distance/#/description 
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,i,j,ans=0;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<32;i++)
        {
            int count=0;
            for(j=0;j<n;j++)
            if(a[j]&(1<<i))
                count++;
            ans += (count*(n-count)*2);
        } 
        cout<<ans<<"\n";   
    }

    return 0;
}