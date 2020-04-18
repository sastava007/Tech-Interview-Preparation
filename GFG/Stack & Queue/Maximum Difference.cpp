/*
    https://practice.geeksforgeeks.org/problems/maximum-difference/1
    We have to find max abs difference b/w nearest smaller element on left and nearest smaller element on right. And if there doesn't exists any such
    elememt then take 0.
    It's a modified version of finding Nearest smallest element to left & Nearest smallest element to right using Stack which uses both of them.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

int main()
{

    IOS;    
    int t;
    cin>>t;
    while (t--)
    {
        int n,i;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];

        stack<int> s1, s2;
        vector<int> ls(n), rs(n); 
        // finding next smaller element of left
        for(i=0;i<n;i++)
        {
            if(s1.empty())
            {
                s1.push(a[i]);
                ls[i]=0;
            }
            else if(!s1.empty() && s1.top()<a[i])
            {
                ls[i]=s1.top();
                s1.push(a[i]);
            }
            else 
            {
                while (!s1.empty() && s1.top()>=a[i])
                {
                    s1.pop();
                }
                if(s1.empty())
                {
                    ls[i]=0;
                    s1.push(a[i]);
                }
                else
                {
                    ls[i]=s1.top();
                    s1.push(a[i]);
                }
            }
        }
        // finding next smaller element on right
        for(i=n-1;i>=0;i--)
        {
            if(s2.empty())
            {
                s2.push(a[i]);
                rs[i]=0;
            }
            else if(!s2.empty() && s2.top()<a[i])
            {
                rs[i]=s2.top();
                s2.push(a[i]);
            }
            else 
            {
                while (!s2.empty() && s2.top()>=a[i])
                {
                    s2.pop();
                }
                if(s2.empty())
                {
                    rs[i]=0;
                    s2.push(a[i]);
                }
                else
                {
                    rs[i]=s2.top();
                    s2.push(a[i]);
                }
            }
        }
        int max_diff = INT_MIN;
        for(i=0;i<n;i++)
            max_diff = max(max_diff, abs(ls[i]-rs[i]));
        cout<<max_diff<<"\n";
    }
    
    return 0;
}