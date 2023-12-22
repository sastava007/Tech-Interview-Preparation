//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
        return 0;
}

// } Driver Code Ends


//User function Template for C++


void solution1(int arr[], int n){
    for(int i = n-1; i > 0; i--){
        swap(arr[i], arr[i-1]);
    }
}


void solution2(int arr[], int n){
    reverse(arr, arr+n-1);
    reverse(arr, arr+n);
    
}

void solution3(int arr[], int n){
    int temp = arr[n-1];
    
    for(int i = n-1; i>=0; i--){
        arr[i] = arr[i-1];
    }
    
    arr[0] = temp;
    
}

void rotate(int arr[], int n)
{
    // Solution 1
    solution1(arr, n);
    
    // Solution 2
    solution2(arr, n);
    
    // Solution 3
    
    solution3(arr, n)
    
    
}
