/*
    Best question of <stack>, got to learn so many new concepts from basic conversions b/w (char<->string) to handling integers, characters and brackets in a single stack
    
    https://practice.geeksforgeeks.org/problems/decode-the-string/0
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

int main()
{
    int t,i;
    cin>>t;
    while (t--)
    {
        string a;
        cin>>a;

        stack<string> s;

        for(i=0; i<a.length(); i++)
        {
            if(a[i]==']')
            {
                string temp="", ans="";
                while(!s.empty() && s.top()!="[")
                {
                    temp=s.top()+temp;
                    s.pop();
                }
                if(!s.empty())  //remove that opening bracket, if stack hasn't been empty yet.
                    s.pop();
                // after removing the opening bracket, we are guranteed to have a number
                int num=0, p=1;

                while (!s.empty() && isdigit(s.top()[0]) )
                {
                    num = stoi(s.top())*p + num;
                    p*=10;
                    s.pop();
                }
                for(int j=0;j<num;j++)
                    ans+=temp;

                s.push(ans);    
            }
            else
            {
                string x(1,a[i]);   // to convert char to string
                s.push(x); 
            }
        }
        cout<<s.top()<<"\n";
        s.pop();
    }
    
    return 0;
}