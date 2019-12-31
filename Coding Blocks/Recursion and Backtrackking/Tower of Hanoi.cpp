#include<bits/stdc++.h>
#pragma gcc optimize("ofast")
#include<time.h>
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
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);

    cout<<"Enter number of disk\n";
    int n;
    cin>>n;
    clock_t start,end;
    start=clock();
    towerofhanoi(n,'A','C','B');
    end=clock();

    double time=((double) (end - start)) / CLOCKS_PER_SEC;
    cout<<"\n\n"<<time;

}

