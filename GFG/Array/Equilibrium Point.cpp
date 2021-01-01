/* We can use prefix and suffix arrays for this, but the optimized solution can be made using two variables */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int equilibriumPoint(long long a[], int n) {
    
    ll sum = 0;
    for(int i=0; i<n; i++)
        sum += a[i];

    ll rightSum = sum, leftSum = 0;
    for(int i=0; i<n; i++)
    {   
        rightSum -= a[i];
        if(leftSum == rightSum)
            return i+1;

        leftSum += a[i];    
    }
    return -1;
}