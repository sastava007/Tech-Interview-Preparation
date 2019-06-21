#include<bits/stdc++.h>
using namespace std;

int x,y,gcd;

//bottom up approach
void extended_euclid(int a,int b)
{
    //base case
    if(b==0)
    {
        x=1;
        y=0;
        gcd=a;
        return;
    }
    //recursive case
    extended_euclid(b,a%b);
    int cx=y;
    int cy=x-(a/b)*y;

    x=cx;
    y=cy;
}
main()
{
    // Solve 18x+30y=6
    int a=8,b=7;
    extended_euclid(a,b);
    cout<<(x+b)%b;
}
