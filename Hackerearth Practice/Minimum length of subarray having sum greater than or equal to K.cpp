/*
    BUT THIS ALGO ONLY WORK FOR ALL POSITIVE NUMBERS OR ALL NEGATIVE NUMBERS
    Complexicity: O(n(log n))
*/

#include<bits/stdc++.h>
using namespace std;
main()
{
    int a[10]={1,1,2,1,2,2,3,1,2,2};
    int k=7,diff=10,start=0,curr_sum=0;
    for(int i=0;i<10;i++)
        {
            curr_sum+=a[i];
            while(curr_sum>=k)
            {
                diff=min(diff,i-start+1);
                curr_sum-=a[start++];
            }

        }
        cout<<diff;
}
