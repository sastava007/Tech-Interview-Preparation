#include<bits/stdc++.h>
using namespace std;
int humming_distance(string a,string b,int m)
{
    int i,haming_dist=0;
    for(i=0;i<m;i++)
        if(a[i]!=b[i])
        haming_dist++;
    return haming_dist;
}
main()
{

    string a="shivansh";
    string b="shikamsr";
    cout<<humming_distance(a,b,8);
}
