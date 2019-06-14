#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j,c,count=0;
    cin>>n>>m;
    string s[n];
    for(i=0;i<n;i++)
    cin>>s[i];

    vector<int> v;
    for(i=0;i<n;i++)
    for(j=i+1;j<n;j++)
    {
        unsigned long long a = std::bitset<64>(s[i]).to_ullong();
        unsigned long long b = std::bitset<64>(s[j]).to_ullong();
        unsigned long long c=a|b;
        v.push_back( __builtin_popcount(c));
    }
    int max_ele=*max_element(v.begin(), v.end());
    cout<<max_ele<<"\n";
    for(auto x=v.begin();x!=v.end();x++)
    if(*x==max_ele)
    count++;
    cout<<count;


}
