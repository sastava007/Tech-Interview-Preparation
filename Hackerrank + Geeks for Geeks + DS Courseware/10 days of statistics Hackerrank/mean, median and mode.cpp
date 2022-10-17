#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    int ar[n];
    float s=0.0;
    for(int i=0;i<n;++i)
        cin>>ar[i];
    for(int i=0;i<n;++i)
        s=s+ar[i];
    cout<<s/n<<endl;
    sort(ar,ar+n);
    
   
    if(n%2==0)
    {
        int index=n/2;
        float median=(ar[index]+ar[index-1])/2.0;
        cout<<median<<endl;
    }
    else if(n%2!=0)
    {
        int index2=(n+1)/2;
        float median=ar[index2];
        cout<<median<<endl;
    }

    int mode=0,mc=0,c=0;
    for(int i=0;i<n;++i)
    {
        c=1;
        for(int j=i+1;j<n;++j)
        {
            if(ar[i]==ar[j])
                c++;
        }
        if(c>mc)
        {
            mc=c;
            mode=ar[i];
        }
    }
    cout<<mode;


    return 0;
}
