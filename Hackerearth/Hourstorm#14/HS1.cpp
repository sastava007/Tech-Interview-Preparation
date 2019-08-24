#include<stdio.h>
#include<math.h>
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"
main()
{
    ll a,b,n;
    while(scanf("%lld%lld%lld",&a,&n,&b)!=EOF)
    {
        ll x=1,c=0;
        while(x)
        {
            ll dig=(ll)floor((log(a)+x*log(x))/log(b))+1;
            if(dig==n)
                c++;
            if(dig>n)
                break;
            x++;
        }
        printf("%lld\n",c);
    }

}
