
/*     Modified DFS used on strings very good problem
 *     https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/gudi-trapped-in-the-room-july-easy/
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

set<string> G;
void dfs(string s, int a, int h)
{
    int n=s.length();
    string temp=s;

    G.insert(s);

    for(int i=0;i<n;i++)
        temp[(i+h)%n]=s[i];
    if(G.find(temp)==G.end())
    dfs(temp,a,h);

    temp=s;
    for(int i=0;i<n;i++)
    {
        if(i%2)     //means even index - we are using 1 based indexing
        temp[i]='0'+(s[i]-'0'+a)%10;
    }
    if(G.find(temp)==G.end())
    dfs(temp,a,h);

    return;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int a,h;
        cin>>a>>h;
        G.clear();
        dfs(s,a,h);
        cout<<*G.begin()<<"\n";
    }
}
