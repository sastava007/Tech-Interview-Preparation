class RecentCounter {
public:
    vector<int>v;
    int c;
    RecentCounter() {
        c=0;
    }
    int find(vector<int>v, int t)
    {
        int mid=0,x=1,start=0,end=v.size()-1;
        if(t-3000>=1)
        {
            x=t-3000;
        }
        while(start<=end)
        {
            mid=(start+end)/2;
            if(v[mid]==x)
            {
                return mid;
            }
            else if(v[mid]>x)
            {
                end=mid-1;
                if(end>=0 && v[end]<x)
                {
                    return mid;
                }
            }
            else
            {
                start=mid+1;
            }
        }
        return mid;
    }
    int ping(int t) {
        c++;
        v.push_back(t);
        int index=find(v,t);
        int ans=c-index;
        return ans;
    }
};