/* 
    Given two arrays A & B of Length N, determine if there is a way to make A equal to B by reversing any subarrays from array B any number of times.
    
    Since w're allowed to reverse any length string, we can actually create A by reversing any permutation of B. So now the problem boild down to checking if array B is a permutation of A or not

*/

bool areTheyEqual(vector<int>& a, vector<int>& b)
{    
    if(s.size()!=b.size())
        return false;
        
    unordered_map<int,int>mymap;
    
    for(int x:a)mymap[x]++;
    for(int x:b)mymap[x]--;
    
    for(auto it=mymap.begin();it!=mymap.end();++it)
        if(it->second != 0)return false;
        
    return true;
}