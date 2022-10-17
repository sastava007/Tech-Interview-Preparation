#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//least square regression
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    double x,y;
    double sumx=0.00,sumy=0.00;
    double sq_sumx=0.00,sq_sumy=0.00,sum_xy=0.00;

    for(int i=0;i<5;++i)
    {    cin>>x>>y;
        sumx=sumx+x;
        sumy=sumy+y;
        sq_sumx=sq_sumx+pow(x,2);
        sum_xy=sum_xy+x*y;
    }
    double meanx=sumx/5;
    double meany=sumx/5;

    double b=(5*sum_xy-(sumx*sumy))/(5*sq_sumx-pow(sumx,2));
    double a=meany-b*meanx;
    double Y=a+(b*80)-1;
    cout<<fixed<<setprecision(3)<<Y<<endl;
    return 0;
}
