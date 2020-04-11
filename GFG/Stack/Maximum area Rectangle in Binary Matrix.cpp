/*
    This problem can be solved by breaking into maximum area histogram(MAH) problem. Each row can be considered as a histogram and we can pass it to MAH() that will return the area
    and we can keep on comparing the obtained area with maximum area. 
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);


int MAH(int a[], int n)
{
    int i, ans=0;
    stack<int> s;
    vector<int> nsl(n),nsr(n);

    //finding nearest smaller to left
    for(i=0;i<n;i++)
    {
        if(s.empty())
            nsl[i]=-1;
        else if(a[s.top()]<a[i])
            nsl[i]=s.top();
        else
        {
            while (!s.empty() && a[s.top()]>=a[i])
                s.pop();
            if(s.empty())
                nsl[i]=-1;
            else
                nsl[i]=s.top();
        }
        s.push(i);
    }

    while(!s.empty())
        s.pop();

    // finding nearest smaller element to right
    for(i=n-1;i>=0;i--)
    {
        if(s.empty())
            nsr[i]=n;
        else if(a[s.top()]<a[i])
            nsr[i]=s.top();
        else
        {
            while (!s.empty() && a[s.top()]>=a[i])
                s.pop();
            if(s.empty())
                nsr[i]=n;
            else
                nsr[i]=s.top();
        }
        s.push(i);
    }
    
    for(i=0;i<n;i++)
        ans=max(ans, a[i]*(nsr[i]-nsl[i]-1));
    return ans;
}

int main()
{
    // IOS; 
    int t,i;
    cin>>t;
    while (t--)
    {
        int n,m,i,j;
        cin>>n>>m;
        int a[n][m];

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                cin>>a[i][j];
        
        int temp[m]={0}, ans=0;

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                a[i][j]!=0?(temp[j]+=a[i][j]):(temp[j]=0);

            ans=max(ans, MAH(temp,m));
        }
        cout<<ans<<"\n";   
    }
    
    return 0;
}