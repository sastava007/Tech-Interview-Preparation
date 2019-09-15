#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"
bool isSame(char a, char b)
{
    if((((int)a>=65 && (int)a<=90)&&((int)b>=97 && (int)b<=122))|| (((int)a>=97 && (int)a<=122)&&((int)b>=65 && (int)b<=90)))
        return false;
    else
        return true;
}
char change(char x)
{
    if((int)x>=65&&(int)x<=90)
    {
        x=(char)(97+x-'A');
        return x;
    }
    else
    {
        x=(char)(65+x-'a');
        return x;
    }
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t=3;
    while(t--)
    {
        string a;
    cin>>a;
        int i=0,c=0,n=a.length();
        for(i=0;i<n;i++)
        {
            if(i!=0&&(i+1)<n&&isSame(a[i-1],a[i+1])&&isSame(a[i],a[i-1]))
                {
                    a[i]=change(a[i]);
                    c++;
                }
            else if(i==0 && isSame(a[i],a[i+1]))
                {
                    a[i]=change(a[i]);
                    c++;
                }
            else if(i==n-1 && isSame(a[i],a[i-1]))
                {
                    a[i]=change(a[i]);
                    c++;
                }
            else if(((i-1)>=0 && isSame(a[i],a[i-1]))||(i+1<n && isSame(a[i],a[i+1])))
                    {
                        a[i]=change(a[i]);
                        c++;
                    }
        }
        cout<<a<<" "<<c<<"\n";
    }

}
