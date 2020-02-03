/*
    https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
    Approach: The idea is to keep adding elements to a temporary variable untill it's sum is <= than given sum and checking if it's values is equal is equal to sum. 
                Once we found the sum break the loop and return but if the value of sum get greater that given value then reset the sum & value of i.  
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        ll n,s,i=0,j=0;
        cin>>n>>s;
        ll a[n];
        for(i=0;i<n;i++)
        cin>>a[i];
        i=0;
        ll temp=0;
        bool found=false;
        while(i<n && j<n)
        {
                temp+=a[i];
                i++;
                
            if(temp==s)
            {
                found=true;
                break;
            }
            if(temp>s)
            {
                temp=0;
                j++;
                i=j;
            } 
        }
        found?cout<<j+1<<" "<<i<<"\n":cout<<"-1\n";
    }
    return 0;
    
}
