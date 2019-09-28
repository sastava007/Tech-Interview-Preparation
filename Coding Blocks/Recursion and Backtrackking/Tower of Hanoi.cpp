#include<bits/stdc++.h>
using namespace std;

void towerofhanoi(int n, char src, char dest, char helper)
{
    // base case
    if(n==1)
    {
        cout<<"shift "<<1<<" disk from "<<src<<" to "<<dest<<"\n";
        return;
    }
    //recursive case
    towerofhanoi(n-1,src,helper,dest);
    cout<<"shift "<<n<<" disk from "<<src<<" to "<<dest<<"\n";
    towerofhanoi(n-1,helper,dest,src);
}
main()
{
    cout<<"Enter number of disk\n";
    int n;
    cin>>n;
    towerofhanoi(n,'A','C','B');
}

