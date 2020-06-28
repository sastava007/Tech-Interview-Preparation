/* 
    We need to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag.

    Idea:   to iterate through the string
            find the longest/farthest bold word ending index for each starting index in string s
            connect them if needed, to obatin the longest ending bold index      
            Form the result.
    
    Example:
        s = "aaabbcc"
        dict = ["aaa","aab","bc"]
        Output: 
        "<b>aaabbc</b>c"

    TC: O(l*N*W) where l is length of string, N is no. of words in string, and W is the maximum word length in dictionary
    Space: O(l)
*/

string addBoldTag(string &s, vector<string> &dict) 
{
    bool bold[s.size()] = {false};  // bold[i] represents whether ith character is part of bold tag or not
    for (int i = 0; i < s.size(); i++)
    {   
        int end = 0;

        for (auto & word : dict)    //find the longest bold word ending index, for each starting index in S
        {
            if (s.compare(i, word.size(), word) == 0)   // check if current substring is in dictionary or not
            {
                end = max(end, i + word.size());
            }
        }
        bold[i] = (end > i);    //we only need to mark the longest string under bold
    }

    string result = "";
    for (int i = 0; i < s.length(); i++) 
    {
        if (!bold[i])   //if not bold, then simply keep on adding them to resultant array
        {
            result += s[i];
            continue;
        }

        int j = i;  //if bold, then find the ending index upto which we have to mark them as bold, and cover that substring under bold tag
        while (j < s.size() && bold[j])
            j++;
        result = result + ("<b>" + s.substr(i, j - i) + "</b>");
        i = j - 1;
    }
    
    return result;
}