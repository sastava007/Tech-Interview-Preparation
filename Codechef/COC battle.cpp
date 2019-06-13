#include<bits/stdc++.h>
using namespace std;

void compute_lps(string &pat,int *lps, int l)
{
    lps[0]=0;
    int i=1;
    int j=0;
    while(i<l)
    {
        if(pat[i]==pat[j])
        {
            j++;
            lps[i]=j;
            i++;
        }
        else // when pat[i]!=pat[j]
        {
            if(j!=0)
                j=lps[j-1];
            else
            {
                lps[i]=0;
                i++;
            }

        }

    }
}

int kmp_search(string &txt,string &pat,int n,int m)
{
    int lps[m];
    compute_lps(pat,lps,m);

    int i=0,j=0;
    int c=0;

    while(i<n)
    {
        if(txt[i]==pat[j])
        {
            i++;
            j++;
        }
        else if(j==m)
        {
            c++;
            j=lps[j-1];
        }
        else if(i<n && pat[j]!=txt[i])
        {
            if(j!=0)
                j=lps[j-1];
            else
                i++;
        }
    }
    return c;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k;
    string txt,pat;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cin>>txt;
        cin>>pat;
        pat=pat.substr(0,k);
        int c=kmp_search(txt,pat,n,k);
        if(c!=0)
            cout<<c<<"\n";
        else
            cout<<"-1\n";
    }

}
