/*  Greedy Approach is to find the most frequently occuring character, and seperate them with the second most frequently occuring character. And if we can do that, then it will gurantee us that no
    two similar characters are adjacent. So we basically need a DS, that allow us to know that this is the most frequently occuring character, this is the second most frequently character which 
    indicates toward max_heap.
    Similar to Schedule Task problem 

    TC: O(NLogN) where N is n. of unique characters in string
    Space: O(N)
 */

class Solution 
{
public:
    string reorganizeString(string s) 
    {
        unordered_map<char, int> m;
        
        for(char c: s)
            m[c]++;

        priority_queue<pair<int, char>> q;
        
        for(auto it: m)
            q.push({it.second, it.first});
        
        string result="";
        
        while(q.size()>1)   //here we're checking for size>1, unlike typical >0 becz we've to extract pop() two elements from top
        {
            auto current = q.top();
                q.pop();
            result += string(1, current.second);
            
            auto next = q.top();
                q.pop();
            result += string(1,next.second);
            
            if(current.first>1)     // if we have more instances of character, then enqueue them again in max_heap
                q.push({current.first-1, current.second});
            if(next.first>1)
                q.push({next.first-1, next.second});
        }
        
        if(!q.empty())  //if we'are left with 1 character, and it has more than 1 instances then there's no way to seperate it, so return ""
        {
            if(q.top().first>1)
                return "";           
            result += string(1, q.top().second);
        }
        
        return result;
    }
};