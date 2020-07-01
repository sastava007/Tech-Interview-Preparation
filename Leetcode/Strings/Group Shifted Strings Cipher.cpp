/*  Find a common shifting pattern, and all strings which has a common shifting pattern should add them to that bucket.
    PS: If asked to return the inner strings in lexogrphically sorted order, and no repition then use set, else use vector and later sort it accordingly

    TC: O(nlogn * W) where W is maximum string length, becz we've to return in lexograpically order else O(N*W)
    Note: For the return value, each inner list's elements must follow the lexicographic order.

    Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"]
    Output: [
                ["abc","bcd","xyz"],
                ["az","ba"],
                ["acef"],
                ["a","z"]
            ]
 */

#include<bits/stdc++.h>
using namespace std;

string getDiff(string s)
{
    string shift="";

    for(int i=1; i<s.length(); i++)
    {
        int diff = s[i]-s[i-1];
        if(diff<0)  //in case s[i] char is lexographically smaller than s[i+1]
            diff += 26;

        shift += (diff+'a');    
    }
    return shift;
}

vector<vector<string>> groupShiftedString(vector<string> arr)
{
    unordered_map<string, set<string>> m;
    for(string s: arr)
    {
        string shift = getDiff(s);
        m[shift].insert(s);
    }

    vector<vector<string>> result;
    for(auto it: m)
    {
        vector<string> group;
        for(string s: it.second)
        {
            group.push_back(s);
        }
        result.push_back(group);
    }
    return result;
}