#include <bits/stdc++.h>
using namespace std;
long long int check(long long int st,long long int end,vector<long long int>arr,long long int c)
{
    for(long long int i=st;i<end;)
    {
        if(c+arr[i]-arr[i+1]>c)
        {
            c=c+arr[i]-arr[i+1];
            i+=2;
        }
        else
            i++;
    }
    return c;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n;
	    cin>>n;
	    vector<long long int>arr;

	    long long int res=0;
	    long long int a;
	    for(long long int i=0;i<n;i++)
	    {
	        cin>>a;
	        arr.push_back(a);
	        res+=(a*(i+1));
	    }
	    //arr.push_back(a);arr.push_back(a);
	    long long h=check(0,n-1,arr,res);
        if(h>res)
	    cout<<h<<"\n";
	    else
        cout<<res<<"\n";
	}
	return 0;
}
