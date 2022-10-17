#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    double mean;
    cin>>mean;
    int k;
    cin>>k;
    long long int k_f=1;
    for(long long int i=1;i<=k;++i)
        k_f=(k_f*i);
    double pd=(pow(mean,k)*pow(2.71828,-(mean)))/k_f;
    cout<<fixed<<setprecision(3)<<pd<<endl;
    return 0;
}
