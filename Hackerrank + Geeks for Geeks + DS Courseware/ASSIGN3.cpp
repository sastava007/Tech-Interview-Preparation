#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,i,j,k,sum=0;
    cout<<"Enter order of matrix:"<<endl;
    cin>>n;
    int arr[n][n],trp[n][n],idt[n][n];
    cout<<"Enter elements of matrix:"<<endl;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>arr[i][j];
    /* to find Transpose & Identity matrix */
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            trp[i][j]=arr[j][i];
            if(i==j)
                idt[i][j]=1;
            else
                idt[i][j]=0;
        }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
               {
                  sum+=arr[i][k]*trp[k][j];
               }
            if(sum!=idt[i][j])
            {
                cout<<"Matrix is not Orthogonal!"<<endl;
                exit(0);
            }
            sum=0;
        }
    cout<<"Matrix is Orthogonal!"<<endl;
}
