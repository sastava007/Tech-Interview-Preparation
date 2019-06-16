/*
    Boston Number: If sum of digits of number is equal to the sum of all prime factors of that number

*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll primeFactors(ll n)
{
    ll prime_sum=0;
    while (n % 2 == 0)
    {
        prime_sum+=2;
        n = n/2;
    }

    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            ll j=i;
            while(j>0)
            {
                prime_sum+=j%10;
                j/=10;
            }

            n = n/i;
        }
    }

    if (n > 2)
    {
        while(n>0)
        {
            prime_sum+=n%10;
            n/=10;
        }
    }

    return prime_sum;
}
main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin>>n;
    ll sum1=primeFactors(n),sum2=0;
    while(n>0)
    {
        sum2+=n%10;
        n/=10;
    }
    if(sum2==sum1)
        cout<<"1";
    else
        cout<<"0";
}
