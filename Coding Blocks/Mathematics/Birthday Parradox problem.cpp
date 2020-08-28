/*
    Find number of people present in room so that probability of two person having birthday on same date is always greater than p(input)
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    double in,p;
    cin>>in;
    double num=365,den=365;
    p=1.0;
    num--;
    int n=1;
    // p is the probability of all persons having birthday on different dates
    while(p>(1.0-in))
    {
        p*=(num/den);
        num--;
        n++;
    }
    cout<<n;
}
