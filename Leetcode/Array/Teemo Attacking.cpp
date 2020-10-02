class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) 
    {
        int ans=0;
        if(timeSeries.size()==0)
        {
            return ans;
        }
        ans+=duration;
        for(int i=1;i<timeSeries.size();i++)
        {
            if(timeSeries[i]-timeSeries[i-1]>=duration)
            {
                ans+=duration;
            }
            else
            {
                ans+=timeSeries[i]-timeSeries[i-1];
            }
        }
        return ans;
    }
};