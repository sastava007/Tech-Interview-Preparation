#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define _f first
#define _s second
#define mp make_pair
#define pb push_back
#define sc(t) scanf("%d",&t)
#define G getchar_unlocked
#define P putchar_unlocked
#define min(x,y) (x<y?x:y)
const int N=100005;

// int a[N],b[N];
// vector <int> v[N];

int main()
{
	ll n,k,i,j,ans,x,y,lim=0;
	
	cin>>n>>k;
	// ans=(n*(n+1))/2;
	for(i=1;i<=n;i++)
    {
		cin>>a[i];
		if(lim < a[i]-k)	
            lim=a[i]-k;
	}
	
	x=0;
	for(i=1;i<=n;i++)
    {
		if(a[i]>=k)
        {
			y=0;
			if(a[i]>k)
            {
                for(j=0;j<=lim;j+=a[i])
                    if(v[j].size()&&y<v[j][v[j].size()-1])	
                        y=v[j][v[j].size()-1];

                if(y>x)	
                    b[i]=y,x=y;
            }
			v[a[i]-k].push_back(i);
		}
	}
	
	ll result = 0;
	
	x=0;
	for(i=2;i<=n;i++)
		if(b[i]&&x<b[i])	
            {
                result += ((b[i]-x)*(n-i+1));
                x=b[i];
            }
	
	cout<<result;
	
	return 0;
}


/* C Code */

// int n,k,zeropos = 0,pos[100010];
// long long ans = 0;
// int max(int a,int b)
// {
//     return a>b?a:b;
// }
// void work(int x,int p)
// {
//     int i;
//     if(!x) { zeropos = p; return;}
//     for(i=1;i*i<=x;i++) if(!(x%i)) { pos[i] = p; pos[x/i] = p;}
// }
// int main()
// {
//     int i,x,last = 0;
//     scanf("%d%d",&n,&k);
//     for(i=1;i<=n;i++)
//     {
//         scanf("%d",&x);
//         if(x>k) last = max(last,max(zeropos,pos[x]));
//         ans += i-last;
//         if(x>=k) work(x-k,i);
//     }
//     ans = (n*(n+1))/2 - ans;

//     printf("%lld",ans);

//     return 0;
// }