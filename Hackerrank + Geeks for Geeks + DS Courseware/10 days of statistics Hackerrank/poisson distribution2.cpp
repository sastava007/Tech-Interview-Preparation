#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    double X,Y;
    cin>>X>>Y;

    double Ca=160+40*(X+pow(X,2));

    double Cb=128+40*(Y+pow(Y,2));
    cout<<fixed<<setprecision(3)<<Ca<<endl;
    cout<<fixed<<setprecision(3)<<Cb<<endl;

    return 0;
}
