#include<bits/stdc++.h>
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i;
    cin>>n;
    map<string,int> lab;
    string dept;

    for(i=0;i<n;i++)
    {    cin>>dept;
        lab[dept]++;
    }
    for(auto it:lab)
    cout<<it.first<<" "<<it.second<<"\n";


}
