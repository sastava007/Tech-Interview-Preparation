#include<bits/stdc++.h>
using namespace std;
main()
{
    int t,n,k,i,j,c;
    char ele,first;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        c=0;
        for(i=0;i<n;i++)
        {
            stack< pair<char,int> > s;
            for(j=0;j<n;j++)
            {
                cin>>ele;
                if(j==0)
                first=ele;
                if(ele==first)      //to store the first encountered element of every row in the stack
                    s.push(make_pair(ele,j));
                else if((j-s.top().second)<=k)
                {
                    s.pop();
                    c++;
                }
            }
        }
       cout<<c<<endl;
    }
}

