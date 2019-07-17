#include<bits/stdc++.h>
using namespace std;
#define ll long long

void permute(char *in, int i)
{
    if(in[i]=='\0')
    {
        cout<<in<<" ";
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
    char in[100],out[100];
    cin>>in;
    permute(in,0);
}

