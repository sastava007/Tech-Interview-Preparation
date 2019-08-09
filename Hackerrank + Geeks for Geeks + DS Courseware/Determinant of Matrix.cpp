#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<<"\n";
#define max_size 6

int ans=0;

class solution
{
    public:
    void getCofactor(int a[][max_size], int cof[][max_size], int x, int y, int n)
    {
        int i,j;
        int row=0,col=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i!=x && j!=y)
                {
                    cof[row][col]=a[i][j];
                    col++;
                }
                if(col==n)
                {
                    col%=n;
                    row++;
                }
            }
        }
    }

    int getDeterminant(int a[max_size][max_size], int n)
    {
        if(n==1)
            return a[0][0];
        int i;
        int cof[max_size][max_size];

        for(i=0;i<n;i++)
        {
            getCofactor(a,cof,0,i,n);
            ans+=(pow(-1,i)*a[0][i]*getDeterminant(cof,n-1));
        }

        return ans;
    }

};

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solution matrix;
    int n,i,j;
    cin>>n;

    int a[max_size][max_size];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        cin>>a[i][j];

    cout<<matrix.getDeterminant(a,n);


}

