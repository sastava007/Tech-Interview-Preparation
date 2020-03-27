/*
    https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1
    Solved using two pointer technique, O(N2) TC and O(1) SC
*/

bool findTriplets(int arr[], int n)
{ 
    sort(arr,arr+n);
    for(int i=0;i<n-1;i++)
    {
        int l=i+1, r=n-1;
        while(l<r)
        {
            if(arr[i]+arr[l]+arr[r]==0)
                return true;
            if(arr[i]+arr[l]+arr[r]<0)
                l++;
            else
                r--;
        }
    }
    return false;
}