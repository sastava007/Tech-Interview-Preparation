#include<bits/stdc++.h>
using namespace std;

// Here we have implemented sieve of eranthostenes and its time complexicity is O(n log(log(n))) by making 2 modifications:
//    1) Mark only odd numbers as true at first
//    2) Start iterating from i*i because all the numbers less than it has been already cancelled
//    3) In loop i as well as j will be odd, so instead of doing j+=i which will be even bcoz odd+odd=even
//      we can modify this as odd+even to yield odd becz we need to check odd numbes only that whether they are prime or not

void find_prime(int n)
{
    int i,j;
    bool prime[n]={false};
    prime[0]=false;
    prime[1]=false;
    prime[2]=true;
    for(i=3;i<n;i+=2)
        prime[i]=true;


    for(i=3;i<n;i+=2)
    {
        if(prime[i])
        for(j=i*i;j<n;j+= 2*i)
            prime[j]=false;
    }


    for(j=0;j<n;j++)
        if(prime[j])
        cout<<j<<endl;
}
main()
{
    int n,i;
    cin>>n;

    // Optimisation1: Mark only odd numbers as true because even numbers are not prime except 2


    find_prime(n);

}
