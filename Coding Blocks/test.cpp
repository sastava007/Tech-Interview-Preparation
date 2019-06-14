#include<iostream>
#define ull unsigned long long
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    ull a[n];
    if(n>=130)
    {
             printf("Yes\n");
             return 0;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%llu",&a[i]);
    }
    for(int i=0;i<n-3;i++)
            for(int j=i+1;j<n-2;j++)
                    for(int k=j+1;k<n-1;k++)
                            for(int l=k+1;l<n;l++)
                                    if((a[i]^a[j]^a[k]^a[l])==0)
                                    {
                                        printf("Yes\n");
                                        return 0;
                                    }

    printf("No\n");
    return 0;
}
