#include<bits/stdc++.h>
#define mp make_pair(a,b)
using namespace std;
void swape(long int *x,long int *y)
{
    long int temp=*x;
    *x=*y;
    *y=temp;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int n,i,m,j=0;
    cin>>n>>m;
    long int ele;
    vector<long int> fr,el;

    for(i=0;i<n;i++)
    {
        cin>>ele;
        vector<long int>::iterator it=find(el.begin(),el.end(),ele);
        if(it==el.end())
        {
            el.push_back(ele);
            fr.push_back(1);
        }
        else
        {
            fr[it-el.begin()]++;
        }

    }

    //both the vectors will be of same size.

    int l=fr.size();
    for(i=0;i<l;i++)
    {
        for(j=0;j<l-i-1;j++)
            if(fr[j]<fr[j+1])
        {
            swape(&el[j],&el[j+1]);
            swape(&fr[j],&fr[j+1]);
        }
    }
    for(i=0;i<l;i++)
        for(j=0;j<fr[i];j++)
        cout<<el[i]<<" ";

}
