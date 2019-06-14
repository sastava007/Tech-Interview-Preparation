#include<bits/stdc++.h>
using namespace std;
main()
{
    int p1,p2,s1,s2;
    cout<<"Enter P1 and S1"<<endl;
    cin>>p1>>s1;
    cout<<"Enter P2 and S2"<<endl;
    cin>>p2>>s2;
    if(p2>p1&&s2>s1)
        cout<<"NEVER Meet"<<endl;
    else
    {
        if((p2-p1)%(s2-s1)==0||(s2-s1)%(p2-p1)==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

}
