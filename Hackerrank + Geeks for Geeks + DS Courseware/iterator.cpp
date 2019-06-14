#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
main()
{

    vector<int> v1(6);
    v1={111,24,13,45,53,62};
    int a[]={2,4,67,7,3,1,0,56};
   // vector<int>::iterator x=*min_element(v1.begin(),v1.end())-v1.begin();

   sort(a,a+8,greater<int>());
   for(int i=0;i<8;i++)
    cout<<a[i]<<" ";
}
