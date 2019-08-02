/* Another solution may also be possible, but it's not working https://ideone.com/zdB4Py  */

#include<bits/stdc++.h>
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int c=0;
        for(int i=0;i<s.length();i++)
        if(s[i]=='1')
        c++;
        if(c&1)
        cout<<"WIN\n";
        else
        cout<<"LOSE\n";
    }

}
