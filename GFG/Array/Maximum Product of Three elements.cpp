/* We can sort the array in descending order, and then the ans will be maximum of first three elements or last two elements*first one.
    Here I've considered last 2 elements, bcoz last two no may be -ve and product of two negative numbers is always positive. So there are chances that they may
    end up giving maximum product when combined with first element(maximum) element.
    
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        ll n,i,j;
        cin>>n;
        ll a[n];
        
        for(i=0;i<n;i++)
            cin>>a[i];
            
        ll maxA=LLONG_MIN, maxB=LLONG_MIN, maxC=LLONG_MIN;
        ll minA=LLONG_MAX, minB=LLONG_MAX;
        
        for(i=0;i<n;i++)
        {
            if(a[i]>maxA)
            {
                maxC=maxB;
                maxB=maxA;
                maxA=a[i];
            }
            else if(a[i]>maxB)
            {
                maxC=maxB;
                maxB=a[i];
            }
            else if(a[i]>maxC)
            {
                maxC=a[i];
            }
            
            //now find smaller and next smaller element.
            if(a[i]<minA)
            {
                minB=minA;
                minA=a[i];
            }
            else if(a[i]<minB)
            {
                minB=a[i];
            }
        }
        
        ll ans = max(maxA*maxB*maxC, minA*minB*maxA);
        cout<<ans<<"\n";
            
    }
    
    
    return 0;
}