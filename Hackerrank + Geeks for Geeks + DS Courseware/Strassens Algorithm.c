#include<stdio.h>
#include<stdlib.h>
#define max_size 8

void strassenMultiply(int a[][max_size], int b[][max_size], int x, int y, int m, int n)
{
    //if(n)
    //
        if(m==1 && n==1)
            return a[0][0]*b[0][0];

        int **res=(int **)malloc(sizeof(int)*2);
        for(int i=0;i<2;i++)
            res[i]=(int*)malloc(sizeof(int*)*2);


        res[0][0]=a[x][y]*b[x][y]+a[x][n]*b[m][y];
        res[0][1]=a[x][y]*b[x][n]+a[x][n]*b[m][n];
        res[1][0]=a[m][y]*b[x][y]+a[m][n]*b[m][y];
        res[1][1]=a[m][y]*b[x][n]+a[m][n]*b[m][n];

        return res;
    //}


}
main()
{

    int n,i,j;
    scanf("%d",&n);
    int a[n][n],b[n][n];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%d",&b[i][j]);

    //strassenMultiply(a,b,0,0,n);
    int **res=strassenMultiply(a,b,0,0,1,1);
    for(i=0;i<2;i++)
        {
            for(j=0;j<2;j++)
            printf("%d ",a[i][j]);
            printf("\n");
        }
}
