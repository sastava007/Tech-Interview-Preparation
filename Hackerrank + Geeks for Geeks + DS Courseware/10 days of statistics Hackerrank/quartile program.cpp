#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;++i)
        cin>>ar[i];
    sort(ar,ar+n);
    int q1,q2,q3,index,c=0,d=0;
    if(n%2!=0)
    {
        index=n/2;
        q2=ar[index];
        for(int i=0;i<index;++i)
            c++;
        for(int i=0;i<index;++i)
        {
            if(c%2!=0)
            {
                q1=ar[c/2];
            }
            else if(c%2==0)
            {
                q1=(ar[c/2]+ar[(c/2)-1])/2;
            }
        }
        for(int i=index+1;i<n+1;++i)
        {
            if(c%2!=0)
            {
                q3=ar[(3*n)/4];
            }
            else if(c%2==0)
            {
                q3=(ar[(3*n)/4]+ar[((3*n)/4)+1])/2;
            }
        }

        cout<<q1<<endl;
        cout<<q2<<endl;
        cout<<q3<<endl;
    }
    else if(n%2==0)
    {
        q2=(ar[n/2]+ar[(n/2)-1])/2;
        index=n/2;
        for(int i=0;i<index-1;++i)
            d++;
        if(d%2!=0)
        {
            q1=ar[d/2];
            q3=ar[(3*n)/4];
        }
        else if(d%2==0)
        {
            q1=(ar[d/2]+ar[(d/2)-1])/2;
            q3=(ar[(3*n)/4]+ar[((3*n)/4)+1])/2;
        }
        cout<<q1<<endl;
        cout<<q2<<endl;
        cout<<q3<<endl;

    }

    return 0;
}

