class Solution {
public:
    static bool compare(int x,int y)
    {
        string a=to_string(x);
        string b=to_string(y);
        if(a+b>b+a)
            return true;
        return false;
    }
    string largestNumber(vector<int>& nums) 
    {
        string x,ans="";
        int n=nums.size();
        if(n==0)
            return ans;
        sort(nums.begin(),nums.begin()+n,compare);
        if(nums[0]==0)
            return "0";
        for(int i=0;i<n;i++)
        {
            x=to_string(nums[i]); 
            ans+=x;
        }
        return ans;
    }
};