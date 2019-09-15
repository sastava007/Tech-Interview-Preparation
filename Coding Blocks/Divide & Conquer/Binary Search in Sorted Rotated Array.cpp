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

int bsearch(int *a, int low, int high, int key)
{
    int pivot = findPivot(a, low, high);

    if (key >= a[low] && key <= a[pivot])
    {
        high = pivot;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (a[mid] == key)
                return mid;
            else if (key > a[mid])
                low = mid + 1;
            else
            {
                high = mid - 1;
            }
        }
        return -1; // not found
    }
    else
    {
        low = pivot + 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (a[mid] == key)
                return mid;
            else if (key > a[mid])
                low = mid + 1;
            else
            {
                high = mid - 1;
            }
        }
        return -1; // not found
    }
}

main()
{
    int t, i, key, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++)
            cin >> a[i];
        cin >> key;
        cout << bsearch(a, 0, n - 1, key) << "\n";
    }
}
