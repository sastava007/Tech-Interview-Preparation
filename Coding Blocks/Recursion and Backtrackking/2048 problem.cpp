#include<bits/stdc++.h>
using namespace std;
#define ll long long
void compute(unordered_map<int,string> &m,int n)
{
    if(n==0)
        return;
    int res=n%10;
    compute(m,n/10);
    cout<<m[res]<<" ";
    return;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n=2048;
    unordered_map<int,string>m;
    m[0]="zero",m[1]="one",m[2]="two",m[3]="three",m[4]="four",m[5]="five",m[6]="six",m[7]="seven",m[8]="eight",m[9]="nine";
    compute(m,n);
}

