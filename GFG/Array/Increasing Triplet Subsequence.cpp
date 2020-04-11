/*
    https://leetcode.com/problems/increasing-triplet-subsequence/
    
    NOTE: This approach can only be used if asked to check whether exists such subsequence or not, but if asked to return index or values then it would fail
          similar to this https://practice.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1
*/

vector<int> find3Numbers(vector<int> arr, int N) {
    
    vector<int> ans;
    if(arr.size()<3)
        return ans;
    int small = INT_MAX, big = INT_MAX;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]<small)
            small = arr[i];
        else if(arr[i]<big)
            big = arr[i];
        else
        {
            ans.emplace_back(small);
            ans.emplace_back(big);
            ans.emplace_back(arr[i]);
            return ans;
        }
    }
    return ans;
}
