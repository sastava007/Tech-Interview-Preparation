#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include<boost/functional/hash.hpp>
using boost::multiprecision::int128_t;
using namespace std;
#define deb(x) cout<<#x<<" "<<x<<"\n";
#define ll long long
int128_t maxi = 1000000000000;

int value(char c)
{
	if (c >= '0' && c <= '9')
		return (int)c - '0';
	else
		return (int)c - 'A' + 10;
}

int128_t solve(string str, int base)
{
    int128_t power = 1;
    int len =str.length(),i;
	int128_t num = 0;

	for (i = len - 1; i >= 0; i--)
	{
		if (value(str[i]) >= base)
            return -1;
		num += ((int128_t)(value(str[i]) * power));
		power = (int128_t)(power*base);
	}
	return num;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t,i;
    cin>>t;
    while(t--)
    {

    	map<int128_t,ll> m;
        ll n;
        cin>>n;
        for(i=0;i<n;i++)
        {
            int b;
            string s;
            cin>>b>>s;
            if(b==-1)
            {
    			unordered_set<int128_t> fo;
                for(int j=2;j<=36;j++)
            	{
            		int128_t temp=solve(s,j);
            		if(fo.find(temp)==fo.end())
            		{
            			m[temp]++;
            			fo.insert(temp);
            		}
            	}
            }
            else
            m[solve(s,b)]++;
        }
        int128_t ans=-1;
        for(auto it:m)
        if(it.second==n)
        {
        	if(it.first<=maxi && it.first>=0)
               {
            		ans=it.first;
                	break;
               }
        }
        cout<<ans<<"\n";
    }
}
