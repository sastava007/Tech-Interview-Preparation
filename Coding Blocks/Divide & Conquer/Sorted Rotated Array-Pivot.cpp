/*You are given a sorted but rotated array. You need to fine the index of the pivot element of the array where pivot is that element
in the array which is greater than its next element and divides the array into two monotonically increasing halves.*/

#include <bits/stdc++.h>
using namespace std;

int findPivot(int *a, int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (mid > low && a[mid] <= a[mid - 1])
            return mid - 1;

        if (mid < high && a[mid] >= a[mid + 1])
            return mid;

        ///If we have reached till here then it means that mid is a element lying in b/w so now we have one usorted array

        if (a[low] >= a[mid])
            high = mid - 1;

        else
            low = mid + 1;
    }
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, i;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    cout << findPivot(a, 0, n - 1);
}