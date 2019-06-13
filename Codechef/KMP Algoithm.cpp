#include<bits/stdc++.h>
using namespace std;

void compute_lps(char *pat,int *lps,int l)
{
    lps[0]=0;
    int i,j=0;
    for(i=1;i<l;)
    {
        if(pat[i]==pat[j])
        {
            lps[i]=j+1;
            i++;
            j++;
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

void kmp_search(char *txt,char *pat)
{
    int n=strlen(txt);
    int m=strlen(pat);
    int lps[m];
    compute_lps(pat,lps,m);

    int i=0,j=0;
    for(i=0;i<n;)
    {
        if(txt[i]==pat[j])
        {
            i++;
            j++;
        }
        else if(j==m)
        {
            cout<<"pattern found at "<<i-j<<"\n";
            j=lps[j-1];
        }
        else if(i<n && txt[i]!=pat[j])
        {
            if(j>0)
                j=lps[j-1];
            else
                i++;
        }
    }
}




main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char txt[]="AAAAABAAABA";
    char pat[]="AAAA";

    kmp_search(txt,pat);

}
