#include<bits/stdc++.h>
using namespace std;

int tc(int *arr, int n, int hire, int sal, int sev)
{
    int dp[25][41];     // n can be max of 24 months, and no. of employees are b/w [1-41]
    for(int i=0; i<n; i++)
        for(int j=0; j<41; j++)
        dp[i][j] = INT_MAX;

    dp[0][arr[0]] = (hire+sal)*arr[0];
    for(int i=0; i<n-1; i++)
    for(int j=0; j<41; j++)
    {
        if(dp[i][j] != INT_MAX)
        {
            if(arr[i+1]>j)
            {
                dp[i+1][arr[i+1]] = min(dp[i+1][arr[i+1]], dp[i][j] + sal*arr[i+1] + hire*(arr[i+1]-j));
            }
            else
            {
                for(int k=j; k>=arr[i+1]; k--)
                    dp[i+1][k] = min(dp[i+1][k], dp[i][j] + sal*k + (j-k)*sev);
            }
        }
    }
    int ans = INT_MAX;
    for(int i=0;i<41;i++)
        ans = min(dp[n-1][i], ans);

    return ans; 
}

int main()
{
    int arr[] = {14, 10, 11};
    cout<<tc(arr, 3, 5, 6, 7);

    return 0;
}