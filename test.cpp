

#include<iostream>
using namespace std;


int Search(int arr[], int l, int r, int x)
{
    if (r>=l)
    {
        int mid = l + (r - l)/2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return Search(arr, l, mid-1, x);
        return Search(arr, mid+1, r, x);
    }
    return -1;
}


int findPos(int arr[], int key)
{
    int l = 0, h = 1;
    int val = arr[0];
    
    
    while (val < key)
    {
        l = h;
        h = 2*h;
        val = arr[h];
    }
    
    
    return Search(arr, l, h, key);
}


int main()
{
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130,
        140, 160, 170};
    int ans = findPos(arr, 10);
    if (ans==-1)
        cout << "Element not found";
    else
        cout << "Element found at index " << ans;
    return 0;
}




