/*
    Here we can perform atmost 1 flip operation of a subarray which means all the bits of that subarray will be flipped
    So maximum 1 can be obtained by original 1s that are already present + those which are flipped. 
    In order to find which subarray to flip, we can consider this as a maximum contigious subarray problem for all 0s
    So I changed 1 => -1 and 0 => 1 to find the maximum sum that can be achieved with 0 bits

    PS: If all the bits are 1 i.e (maxsum = -1) then in that case we don't need to perform any flip operation.
    Same approach can be used to count max 0s in array by flipping bits: https://www.geeksforgeeks.org/maximize-number-0s-flipping-subarray/
*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,ones=0;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==1)
            {
                ones++;
                a[i]=-1;
            }
            else
            a[i]=1;
        }
        int sum=a[0], maxsum=a[0];
        for(i=1;i<n;i++)
        {
            sum=max(a[i],a[i]+sum);
            maxsum=max(sum,maxsum);
        }
        
        maxsum>=0?cout<<ones+maxsum<<"\n":cout<<ones<<"\n";
    }
	return 0;
}