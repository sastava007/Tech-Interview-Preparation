/* Here we have to do this inplace operation, i.e merge nums2 into nums1 assuming nums1 is large enough to accomodate these elements */
class Solution 
{
    public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int i = m-1;
        int j = n-1;
        
        int e = m+n-1;
        
        while(i>=0 && j>=0)
        {
            if(nums1[i]>nums2[j])
                nums1[e--] = nums1[i--];
            else
                nums1[e--] = nums2[j--]; 
        }
        
        while(j>=0)
            nums1[e--] = nums2[j--];
    }
};