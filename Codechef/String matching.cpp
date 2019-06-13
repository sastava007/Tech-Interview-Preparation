#include<bits/stdc++.h>
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string txt="ABABABCABABABCABABABC";
    string pat="ABABAC";
    int l=txt.length();
    int m=pat.length();
    string kmp;
    int i,j;
    for(i=0;i<=l-2*m;i++)
    {
        kmp="";
        for(j=0;j<m;j++)
        {
        if(txt[i+j]!=pat[j])
            break;
        else
            kmp+=pat[j];
        }
        if(j==m)
        cout<<"Pattern found at "<<i<<"\n";
    }
    cout<<kmp;

}
