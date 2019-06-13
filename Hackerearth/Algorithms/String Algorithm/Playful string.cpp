#include<bits/stdc++.h>
using namespace std;
bool match(string txt,string pat,int n,int m)
{
    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        if(txt[i]==pat[j])
        j++;
    }
    return j==m;

}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    string txt,pat;
    while(t--)
    {
        cin>>txt>>pat;
        bool found=false;
        int n=txt.length();
        int m=pat.length();

        found=match(txt,pat,n,m);
        if(found)
        {
            found=false;
            reverse(pat.begin(),pat.end());
            found=match(txt,pat,n,m);
            if(found)
            cout<<"GOOD STRING\n";
            else
            cout<<"BAD STRING\n";
        }
        else
        cout<<"BAD STRING\n";
    }
}
