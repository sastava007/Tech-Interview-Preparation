/* 
    Find all duplicates in an array.
    As all the no. are in range [1-N] and there are total N numbers so we can use number itself to find the index.
    index = nums[i]-1

    We can flip the value at index to negative, and again if we reach a position where a number is already negative then add that number to result.
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> ans;
        int n=nums.size();
        
        for(int i=0; i<n; i++)  {
            int index = abs(nums[i])-1;
            if(nums[index] < 0)
                ans.push_back(index+1);
            nums[index] = -nums[index];
        }
        
        return ans;
    }
};


/*
    https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1
    This approach works becz all the elements are b/w (0 to n-1), so evenafter adding n to it it wil be (2n-1)/n which is 1

*/
void printDuplicates(int a[], int n) {
    int c=1;
    for(int i=0; i<n; ++i)
    {
        // Here we are moduling it with n, to get it's original value of element that has been lost after adding n so many times
        int ind = a[i] % n;
        a[ind] += n;
    }
    
    for(int i=0; i<n; ++i){
        // a[i]/n will give me frequency of element
        if(a[i]/n > 1){
            cout<<i<<" ";
            c =0;
        }
    }
    
    if(c) cout<<"-1";
}