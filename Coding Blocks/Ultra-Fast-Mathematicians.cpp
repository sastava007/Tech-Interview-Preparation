
#include<bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t,i;
    string a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        int l=a.length();
        for(i=0;i<l;i++)
        a[i]!=b[i]?cout<<"1":cout<<"0";
        cout<<"\n";

    }
	return 0;

}

