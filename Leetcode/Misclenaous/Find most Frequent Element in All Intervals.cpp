/*  FInd most frequent element in all interval
    Note:  The optimal (most frequent point) is reachable in at an interval start or end point.
*/

#include<bits/stdc++.h>
using namespace std;

int mostFrequent(vector<vector<int>>v)
{
    set<int>points;
    unordered_map<int,int>starts,ends;
    
    for(int i=0;i<v.size();i++)
    {
        starts[v[i][0]]++;  // store the frequency of starting & ending interval
        ends[v[i][1]]++;

        points.insert(v[i][0]);
        points.insert(v[i][1]);
    }
    
    int count=0,ans=0,maxTime=0;
    for(auto it=points.begin();it!=points.end();++it)
    {
        int t=*it;
        count+=starts[t];
        if(count>maxTime)
        {
           maxTime=count;
           ans=t;
        }
        count-=ends[t];
    }
    return ans;
}

int main(void){

    cout<<mostFrequent({{1,4},{3,5},{4,6}})<<endl;      // expected 4
    cout<<mostFrequent({{0,2},{3,5}})<<endl;    // expedted 0   but (1,2,3,4,5) are also possible answers

    cout<<mostFrequent({{1,6},{2,3},{2,5},{3,8}})<<endl;
    
    return 0;
}