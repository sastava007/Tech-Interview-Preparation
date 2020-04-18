/*
    https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

    https://letstalkalgorithms.com/find-the-celebrity/
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 501

int getId(int M[MAX][MAX],int n);

int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;

    }
}


int getId(int M[MAX][MAX], int n)
{
    int i, celeb=0;
    for(i=1;i<n;i++)
        if(M[celeb][i]==1)
            celeb=i;
    
    for(i=0;i<n;i++)
    {
        if(i!=celeb && ((M[celeb][i]==1) || (M[i][celeb]==0)))
            return -1; 
    }
    return celeb;
}