/*
    https://practice.geeksforgeeks.org/problems/maximum-sub-array/0
    To find max subarray of non negative elements we have to simply ignore all -ve elements and whenever we encounter them we have to start a new subaaray
*/

#include<bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    
    int t;
    cin>>t;
    while(t--)
    {
        int n; 
        cin>>n;
        int a[n];
        int sum=0, maxsum=0, l=0, r=0, al=-1,ar=-1;
       
        for(r=0;r<n;r++)
        {
            cin>>a[r];
            if(a[r]<0)
            {
                sum=0;
                l=r+1;
            }
            else
            {
                sum += a[r];
                if(sum > maxsum)
                {
                    maxsum = sum;
                    al = l;
                    ar = r;
                }
                else if(sum == maxsum && (r-l+1 > ar-al+1))
                {
                    al = l;
                    ar = r;
                }
            }
        }
        if(al==-1 || ar==-1)
            cout<<"0";
        else
            for(int i=al;i<=ar;i++)
                cout<<a[i]<<" ";
        cout<<"\n";
    }
	return 0;
}