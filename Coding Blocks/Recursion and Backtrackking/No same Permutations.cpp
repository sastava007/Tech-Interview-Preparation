#include<bits/stdc++.h>
using namespace std;
#define ll long long

set<string> ans;
void permute(char *in, int i)
{
    if(in[i]=='\0')
    {
        ans.insert(in);
        return;
    }

    for(int j=i;in[j]!='\0';j++)
    {
        swap(in[i],in[j]);
        permute(in,i+1);
        //Backtracking - to restore the original array
        // jis swap se neeche aaye the use undo karna hoga
        swap(in[i],in[j]);
    }

}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,i,j=0;
    cin>>n;
    n=(2*n-1);
    char in[n],temp;
    for(i=0;i<n;i++)
    {
        cin>>temp;
        if(temp!=' ')
        in[j++]=temp;
    }
    permute(in,0);
    for(auto it:ans)
    cout<<it<<"\n";
}


