#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"

class solution
{

    public:
    void printsolu(int *a, int check,int n)
    {
        if(check==0)
		{
			cout<<"YES"<<"\n";
            for(int i=0;i<n;i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<"\n";
		}

    }


    void solve(int *a, int n, int k)
    {
        int check=0;
        for(int i=0;i<n;i++)
		{
			if(i==0 && i==n-1 && a[i]==-1)
			{
				cout<<"YES"<<"\n"<<"1"<<"\n";
				check=1;
				break;
			}
			else if(i==0 && a[i]==-1)
			{
				if(a[i+1]!=1)
				{
					a[i]=1;
				}
				else
				{
					a[i]=2;
				}
			}
			else if(i==n-1 && a[i]==-1)
			{
				if(a[i-1]!=1)
				{
					a[i]=1;
				}
				else
				{
					a[i]=2;
				}
			}
			else if(a[i]==-1 && i!=0 && i!=n-1)
			{
				if(a[i-1]==1)
				{
					if(a[i+1]!=2)
					{
						a[i]=2;
					}
					else
					{
						if(k>=3)
						{
							a[i]=3;
						}
						else
						{
							cout<<"NO"<<"\n";
							check=1;
							break;
						}
					}
				}
				else if(a[i+1]==1)
				{
					if(a[i-1]!=2)
					{
						a[i]=2;
					}
					else
					{
						if(k>=3)
						{
							a[i]=3;
						}
						else
						{
							cout<<"NO"<<"\n";
							check=1;
							break;
						}
					}
				}
				else
				{
					a[i]=1;
				}
			}
		}
		printsolu(a, check,n);
    }



};
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k,n,tc;
        cin>>tc;
        while(tc--)
        {
            cin>>n>>k;
            int i;
            int a[n];
            for(i=0;i<n;i++)
                {
                    cin>>a[i];
                }
                solution obj;
                obj.solve(a,n,k);


        }

}
