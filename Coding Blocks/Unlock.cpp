#include<bits/stdc++.h>
using namespace std;
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,k,i,swape=0;
	cin>>n>>k;
	long long int v[n],pos[n];

	for(i=0;i<n;i++)
	{
	    cin>>v[i];
	    pos[v[i]]=i;
	}

	i=0;

	while(swape<k && i<n)
	{
		if(v[i]!=n-i)
        {
            long long temp=pos[n-i];
            pos[v[i]]=pos[n-i];
            pos[n-i]=i;


            swap(v[temp],v[i]);
            swape++;
        }
        i++;

	}

	for(i=0;i<n;i++)
	cout<<v[i]<<" ";
	return 0;
}
