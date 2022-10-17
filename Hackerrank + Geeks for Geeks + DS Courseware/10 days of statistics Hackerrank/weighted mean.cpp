#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
    int x[n],w[n];
    for(int i=0;i<n;++i)
        cin>>x[i];
    for(int i=0;i<n;++i)
        cin>>w[i];
    float product=0.0;
    float sum_w=0.0;
    for(int i=0;i<n;++i)
    {
        product=product+(x[i]*w[i]);
        sum_w=sum_w+w[i];
    } 
    float mw=((product)/(sum_w))/1.0;
    

    float value = (int)(mw * 10 + .5); 
    cout<<(float)value / 10; 
    return 0;
}
