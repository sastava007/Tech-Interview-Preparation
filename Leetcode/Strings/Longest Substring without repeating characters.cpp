///    Use two pointer to keep track of elements

#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
    unordered_set<char> temp;

    int max_sub=0,i=0,j=0;

        while(i<s.length() && j<s.length())
        {
            if(temp.find(s[j])==temp.end())
            {
                temp.insert(s[j++]);
            }
            else
            {
                temp.erase(s[i++]);
            }
            max_sub=max(max_sub,j-i);
        }
        return max_sub;
    }
};


///   Another aproach using Unordered_map<>, but this is showing runtime error

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> temp;

    int max_sub=0,i=0,j=0;

        while(j<s.length())
        {
            if(temp.find(s[j])==temp.end())
            {
                temp[s[j]]=j;
            }
            else
            {
                auto it=temp.find(s[j]);
                temp.erase(s[it->second]);
                i=it->second+1;
            }
            max_sub=max(max_sub,j-i);
            j++;
        }
        return max_sub;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    Solution2 obj;
    cout<<obj.lengthOfLongestSubstring(s);

    return 0;
}
