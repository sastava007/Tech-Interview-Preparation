#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int l;
        long long int ans=0;
        cin>>s;
        l=s.length();
        for(int i=1;i<=s.length();i++)
        {
            if(s[i-1]=='a'||s[i-1]=='e'||s[i-1]=='i'||s[i-1]=='o'||s[i-1]=='u'||s[i-1]=='A'||s[i-1]=='E'||s[i-1]=='I'||s[i-1]=='O'||s[i-1]=='U')
            {
                ans+=l*i;
            }
            l--;
        }
        cout<<ans<<endl;
    }
    return 0;

}
