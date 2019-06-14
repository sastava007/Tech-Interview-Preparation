/*Given an array of n integers, The task is to find another integer x such
that, if all the elements of the array are subtracted individually from the number
x, then the sum of all the differences should add to 0. If any such integer
exists, print the value of x, else print -1.*/
#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,i,s=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    if(s%n==0)
        cout<<s/n;
    else
        cout<<"-1";
}
