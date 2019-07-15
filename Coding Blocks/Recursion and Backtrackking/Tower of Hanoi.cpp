#include<bits/stdc++.h>
using namespace std;
#define ll long long

void towerofhanoi(int n, char src, char dest, char helper)
{

    // base case
    if(n==0)
        return;
    //recursive case
    towerofhanoi(n-1,src,helper,dest);
    cout<<"shift "<<n<<" disk from "<<src<<" to "<<dest<<"\n";
    towerofhanoi(n-1,helper,dest,src);
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    towerofhanoi(n,'A','C','B');
}

