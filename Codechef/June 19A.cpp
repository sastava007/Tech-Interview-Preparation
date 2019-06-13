#include<bits/stdc++.h>
using namespace std;
#define ll long long

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t,d,i;
    string s;
    cin>>t;
    int n,proxy;
    double c;

    while(t--)
    {
        cin>>d>>s;
        string temp=s;

        double atd=0;
        c=0;

        for(i=0;i<d;i++)
            if(s[i]=='P')
            c++;
        atd=c/d;

        proxy=0;
        i=2;
        while(atd<0.75 && i<(d-2))
        {

            if((s[i]=='A') && (s[i-1]=='P'||s[i-2]=='P') && (s[i+1]=='P'||s[i+2]=='P'))
            {
                    proxy++;
                    temp[i]='P';
                    c++;
            }


            atd=c/d;
            i++;
        }
        if(atd>=0.75)
            cout<<proxy<<"\n";
        else
            cout<<"-1\n";

    }
}
