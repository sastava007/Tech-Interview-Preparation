/* Main Problem: Trivial solution using hashmap */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int, int> m;
        for(auto it: nums1)
            m[it]++;
        
        vector<int> ans;
        
        for(auto it: nums2)
        {
            if(m.find(it)!=m.end() && --m[it]>=0)
                ans.emplace_back(it);
        }
        
        return ans;
    }
};

/*  Follow Up: If both the arrays already sorted & we've to include the elements as many times as they are present in both the arrays. 
    The intution is similar to merging two sorted arrays, here we'll not skip remaining equal elements when we found an equal pair unlike the problem 1 
    2 Pointers approach, Worst case time complexity: O(m+n)    
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = (int)nums1.size(), n2 = (int)nums2.size();
        int i1 = 0, i2 = 0;
        vector<int> res;
        while(i1 < n1 && i2 < n2){
            if(nums1[i1] == nums2[i2]) {
                res.push_back(nums1[i1]);
                i1++;
                i2++;
            }
            else if(nums1[i1] > nums2[i2]){
                i2++;
            }
            else{
                i1++;
            }
        }
        return res;
    }
};

/* Follow Up: If one array is small and other one is super large then can we achieve better than O(m+n), yes we can achieve O(nlogm) in this case, n < m. 
    for every element, we binary search it on the other array. One thing to note is that the question asks to include duplicates, therefore when we binary search, 
    we need to find the left-most matching number. Since the inputs are sorted, next time we perform a binary search, the low should start the previously found index+1.

    So this case is only useful only if one of the two is relaitevly too large, and other one is too small like. (nums1.size()=3 && nums2.size()=1000)

*/
int bsearch(vector<int> &nums, int low, int high, int target)
{
    while(low<high)
    {
        int mid=(low+high)/2;
        if(target==nums[mid])   //basically give the leftmost occurence of element
            high=mid;
        else if(target<nums[mid])
            high=mid;
        else
            low=mid+1;
    }

    if(low>=0 && low<nums.size() && nums[low]==target)
        return low;
    else
        return -1;
}
vector<int>intersect(vector<int>& nums1, vector<int>& nums2)
{   
    if(nums2.size()<nums1.size())   //nums1 is vector with lesser elements
    {
        nums2.swap(nums1);  //constant time swap operation becz just reference to pointers are exchanged which is a O(1) operation 
    }
    int low=0, high=nums2.size()-1;
    vector<int>ans;

    for(auto it: nums1) //we're assuming nums1 to have lesser elements
    {   
        int index = bsearch(nums2,low,high,target);
        if(index!=-1)
        {
            low=index+1;
            ans.push_back(it);
        }
    }

    return ans;
}