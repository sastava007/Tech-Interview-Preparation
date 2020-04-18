/*
    Another approach with constant space: https://www.geeksforgeeks.org/minimum-number-of-bracket-reversals-needed-to-make-an-expression-balanced-set-2/?ref=rp

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
    return (x=='{' && y=='}');
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
        stack<char> s;
        int reversals=0;

        for(i=0;i<a.length();i++)
        {
            if(s.empty())
                s.push(a[i]);
            else if(isBalanced(s.top(), a[i]))
                s.pop();
            else
                s.push(a[i]);
        }

        a="";
        while(!s.empty())
        {
            a = s.top() + a;
            s.pop();
        }

        for(i=0;i<a.length();i++)
        {
            if(s.empty())
                s.push(a[i]);
            else
            {
                if(s.top() == a[i])
                {
                    s.pop();
                    reversals+=1;
                }
                else
                {
                    s.pop();
                    reversals+=2;
                }
            }
        }
        !s.empty()?cout<<"-1\n":cout<<reversals<<"\n";
    }

    return 0;
}