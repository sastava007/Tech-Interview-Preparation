/* 
    GIven a list of logs (letterlogs & digitlogs) and we've to rearrange them such that all letterlogs comes before any digitlogs. And digitlogs should be in orginal order wheras
    letterlogs should be in lexographically increasing order of values. If two logs have same value then sort them on the basis of identifier.

    Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
    Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]

    TC: O(K* NlogN) and Space: O(N)
*/

vector<string> reorderLogFiles(vector<string>& logs) 
{
    vector<string> digitLogs, ans;      
    vector<pair<string, string>> letterLogs;    // Idea is to store the letterlogs as a pair of (identifier + value) and later we can sort them

    for (string &s : logs)
    {
        int i = 0;
        while (s[i] != ' ')
            i++;
        
        if (isalpha(s[i + 1])) 
            letterLogs.push_back({s.substr(0, i), s.substr(i + 1)});
        else
            digitLogs.push_back(s);
    }
    
    sort(letterLogs.begin(), letterLogs.end(), [&](auto& a, auto& b) {   
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    });
    
    for(auto &p : letterLogs) 
        ans.push_back(p.first + " " + p.second);
        
    for(string &s : digitLogs) 
        ans.push_back(s);
    return ans;
}