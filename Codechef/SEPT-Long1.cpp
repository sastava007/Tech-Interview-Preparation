#include<bits/stdc++.h>
using namespace std;
typedef long long int ull;
main()
{

    ull t;
    cin>>t;

    int fib[60];
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<60;i++)
        fib[i]=(fib[i-1]+fib[i-2])%10;

    while(t--)
    {
        long double n;
        cin>>n;
        ull x=log2(n);
        ull c=pow(2,x);
        c=(c-1)%60;

        cout<<fib[c]<<"\n";

    }
}
