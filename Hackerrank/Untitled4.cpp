#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
main()
{
    vector<int> v{1,2,3,4};
    vector<int>::iterator it=v.begin(),it1=v.end();
    do
    {
       cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<endl;

    }while(next_permutation(it,it1));
}
