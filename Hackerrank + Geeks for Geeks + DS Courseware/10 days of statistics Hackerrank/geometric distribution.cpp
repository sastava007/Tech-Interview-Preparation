#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    float n,d;
    cin>>n>>d;
    int t;
    cin>>t;
    double p=(n*1.000)/(d*1.0000);
    
    double q=1-p;
    double g=pow(q,t-1)*p;

    cout << fixed <<setprecision(3) <<g<<endl;    
    return 0;
}
