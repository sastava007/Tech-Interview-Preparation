#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<<"\n";

bool ifPossible(int m, int sum)
{
    return (sum>=0 && sum<=m*9);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        int m,sum;
        cin>>m>>sum;
        int sum1=sum;

        if(m==1 && sum==0)
            cout<<"0 0";
        else if(m!=0 && sum==0)
            cout<<"-1 -1";
        else if(ifPossible(m,sum))
        {
            string minAns="",maxAns="";
            for(int i=0;i<m;i++)
            {
                for(int d=0;d<10;d++)
                {
                    if((i > 0 || d > 0 || (m == 1 && d == 0))&& ifPossible(m-i-1,sum1-d))    //there shouldn't be any leading zero means when i=0 then d!=0
                    {
                        sum1-=d;
                        minAns+=(char)(d+'0');
                        break;
                    }
                }
            }

            for(int i=0;i<m;i++)
            {
                for(int d=9;d>=0;d--)
                {
                    if((i > 0 || d > 0 || (m == 1 && d == 0))&& ifPossible(m-i-1,sum-d))    //there shouldn't be any leading zero means when i=0 then d!=0
                    {
                        sum-=d;
                        maxAns+=(char)(d+'0');
                        break;
                    }
                }
            }
            cout<<minAns<<" "<<maxAns;
        }
        else
        cout<<"-1 -1"<<"\n";
    return 0;
}

