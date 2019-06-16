/*
                    Check if it is possible to find four elements in array such that their XOR is zero
                    i<j<k<l a[i]^a[j]^a[k]^a[l] =0
                    Using pigeonhole principle, and here each consecutive number differ by just 1 bit so their XOR is always 1
                    Codechef: https://www.codechef.com/problems/GRAYSC
*/

#include<iostream>
#define ull unsigned long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    ull a[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    if(n>=130)
    {
             cout<<"Yes";
    }
    else
    {
        for(int i=0;i<n-3;i++)
            for(int j=i+1;j<n-2;j++)
                for(int k=j+1;k<n-1;k++)
                    for(int l=k+1;l<n;l++)
                        if((a[i]^a[j]^a[k]^a[l])==0)
                            {
                                cout<<"Yes";
                                return 0;
                            }

         cout<<"No";
    }

return 0;
}
