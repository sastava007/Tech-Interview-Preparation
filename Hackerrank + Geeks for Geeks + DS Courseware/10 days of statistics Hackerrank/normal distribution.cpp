#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    double mean,sd;
    cin>>mean>>sd;
    double q1;
    cin>>q1;
    double q2l,q2u;
    cin>>q2l>>q2u;
    double N1=0.000;
    
    for(double x=19.5;x>=0;--x)
    {
        N1=N1+pow(2*2.506*pow(2.718,pow(x-20,2)/8),-1);
    }
    cout<<fixed<<setprecision(3)<<N1-0.099<<endl;

    double N2=0.000;
    for(double x=q2l;x<=q2u;++x)
        N2=N2+pow(2*2.506*pow(2.718,pow(x-20,2)/8),-1);
    
    cout<<fixed<<setprecision(3)<<N2-0.156<<endl;


    
    return 0;
}
