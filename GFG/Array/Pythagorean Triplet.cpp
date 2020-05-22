/* Modified 2 Pointers algo, here outer loop starts from end */

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n, i;
        cin>>n;
        
        ll a[n];
        
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            a[i]*=a[i];
        }
        sort(a, a+n);
        
        bool flag = false;
        
        for(i=n-1;i>=0;i--)
        {
            ll low = 0, high = i-1;
            while(low<high && !flag)
            {
                if(a[i] == a[low]+a[high])
                {
                    flag=true;
                    break;
                }
                else if(a[low]+a[high]<a[i])
                    low++;
                else
                    high--;
            }
        }
        
        flag?cout<<"Yes\n":cout<<"No\n";
            
    }
    
    return 0;
}