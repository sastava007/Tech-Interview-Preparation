#include<bits/stdc++.h>
using namespace std;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int n,m,i,j;
    cin>>n>>m;
    vector<string> s(n);
    for(i=0;i<n;i++)
        cin>>s[i];

    sort(s.begin(),s.end());

    string ans="";

    for(i=0;i<m;i++)
    {
        char ch;
        map<char,int> temp;
        for(j=0;j<n;j++)
        {
            string y=s[j];
            temp[y[i]]++;
        }
        int max_fr=INT_MIN;

        for(auto it:temp)
        {
            if(it.second>max_fr)
            {
                max_fr=it.second;
                ch=it.first;
            }
        }
        ans+=ch;
    }
    cout<<ans;
}
