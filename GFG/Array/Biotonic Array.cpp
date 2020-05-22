#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

ll findPeakElement(ll *nums, ll low, ll high) 
{
    if (low == high)
        return low;
    ll mid = (low + high) / 2;
    if (nums[mid] > nums[mid + 1])
        return findPeakElement(nums, low, mid);
    return findPeakElement(nums, mid + 1, high);
}

// Function for binary search in ascending part of array 
ll ascendingBinarySearch(ll *arr, ll low, ll high, ll key) 
{
    while (low <= high) 
    {
        ll mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

// Function for binary search in descending part of array
ll descendingBinarySearch(ll *arr, ll low, ll high, ll key)
{
    while (low <= high) 
    {
        ll mid = low + (high - low) / 2 ;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            high = mid - 1; 
        else 
            low = mid + 1; 
    }
    return -1;
}

// driver function
ll findBitonic(ll *nums, ll size, ll k) 
{
    ll peak_index = findPeakElement(nums, 0, size-1);
    if(k > nums[peak_index]) 
        return -1;
    else if(k == nums[peak_index]) 
        return peak_index; 
    else {
        ll temp = ascendingBinarySearch(nums, 0, peak_index-1, k); 
        if (temp != -1) 
        { 
            return temp; 
        }
        // Search in right of k 
        temp = descendingBinarySearch(nums, peak_index+1, size-1, k);
        if(temp != -1)
        {
            return temp;
        }
    }
    return -1;
}

int main()
{   
    ll t,i;
    cin>>t;
    while (t--)
    {
        ll n, k;
        cin>>n;
        ll a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        cin>>k;
        
        cout<<findBitonic(a, n, k)<<"\n";
    }

    return 0;
}