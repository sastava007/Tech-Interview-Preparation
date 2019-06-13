#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,i;
    cin>>n;
    int size=2*n;
    int total=0;
    int a[size];
    for(i=0;i<size;i++)
    cin>>a[i];

    sort(a,a+size);

    for(i=0;i<size;i+=2)
    {
        total+=(a[i]<a[i+1]?a[i]:a[i+1]);
    }
    cout<<total;

}
