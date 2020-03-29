/*
    https://www.geeksforgeeks.org/set-bits-n-equals-m-given-range/
    Given two numbers N & M, we have to replace the bits from i-j with M such that M become a subset of N strating and ending at index (i,j)
    respectively.
    1. First we need to clear the bits in N from i-j
    2. Add the M by left shifting it i positions.
*/

#include<bits/stdc++.h>
using namespace std;

void clearRangeBits(int &n, int l, int r)
{   
    // if n=31 0011111, l=1 and r=3 then mask=1110001 mask = a|b where a = 1110000 and b = 0000001 
    // a can be build using (-1)<<(r+1) and b can be using 2^i-1 which is same as 1<<i - 1
    int a = (-1)<<(r+1);
    int b = (1<<l) -1;
    int mask = a|b;
    n=n&mask;
}

int main()
{
    int n,m,i,j;
    cin>>n>>m>>i>>j;
    
    clearRangeBits(n,i,j);
    m=m<<i;
    n=n|m;
    cout<<n;

    return 0;
}