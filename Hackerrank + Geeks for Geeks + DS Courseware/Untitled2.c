#include<bits/stdc++.h>
using namespace std;
main()
{
    int a[5]={'2','4','4','5','2'};
    int s=0;
    for(int i=0;i<5;i++)
    s^=a[i];
    cout<<s;

}
