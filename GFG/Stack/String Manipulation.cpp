/*
    This is a good problem where use of stack is must, becz in most of the problems of finding same conseutive element we can simply do it by maintaining a prev variable
    but here that approach will fail. As we have to perform multiple iterations of same loop.

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

        stack<string> s;
        for(i=0;i<n;i++)
        {
            string temp;
            cin>>temp;
            if(s.empty() || temp!=s.top())
                s.push(temp);
            else if(s.top() == temp)
                s.pop();
        }
        cout<<s.size()<<"\n";
            
    }
    
    return 0;
}