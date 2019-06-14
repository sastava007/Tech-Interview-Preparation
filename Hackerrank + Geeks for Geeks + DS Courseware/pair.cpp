#include<iostream>
#include<utility>
#include<bits/stdc++.h>
using namespace std;
main()
{

    pair<int,pair<int,int>> P;
    P.first=2;
    P.second.first=3;
    P.second.second=4;
    cout<<P.first<<" "<<P.second.first<<" "<<P.second.second;
}
