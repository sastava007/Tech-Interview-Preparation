
/*
    Though, their can be various possible solution to this but I solved this by breaking down it into two known classical problems i.e 
    Parenthesis Validation & longest subarray of non-negative integers.

    https://practice.geeksforgeeks.org/problems/longest-valid-parentheses/0 
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

bool isBalanced(char x, char y)
{
    return (x=='(' && y==')');
}

int main()
{
    // IOS;    
    int t,i;
    cin>>t;
    while (t--)
    {
        string a;
        cin>>a;

        stack<pair<char, int>> s;
        int arr[a.length()];

        for(i=0;i<a.length();i++)
        {
            if(s.empty())
                s.push({a[i], i});
            else if(isBalanced(s.top().first, a[i]))
            {
                arr[s.top().second]=1;
                arr[i]=1;
                s.pop();
            }
            else
                s.push({a[i], i});
        }

        while (!s.empty())
        {
            arr[s.top().second]=-1;
            s.pop();
        }

        int count=0, max_count=0;
        for(auto it:arr)
        {
            if(it==-1)
            {
                max_count=max(max_count, count);
                count=0;
            }
            else
            {
                count++;
            }
        }
        max_count=max(max_count, count);
        cout<<max_count<<"\n";

    }
    return 0;
}

/* One more solution without using extra array for storing indices, here we are pushing a extra pair{-1,-1} to build base for our valid substrings */

int main()
{
    int t,i;
    cin>>t;
    while (t--)
    {
        string a;
        cin>>a;

        stack<pair<char, int>> s;
        s.push({-1,-1});

        int max_count=0;

        for(i=0;i<a.length();i++)
        {
            if(s.size()==1)
                s.push({a[i], i});
            else if(isBalanced(s.top().first, a[i]))
            {
                pair<char, int> top = s.top();
                    s.pop();
                if(!s.empty())
                {
                    max_count = max(max_count, i-s.top().second);
                }
                else
                s.push(top);
            }
            else
                s.push({a[i], i});
        }
        cout<<max_count<<"\n";
    }
    return 0;
}