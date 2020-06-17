/* 
    Idea:   to loop through the string
            find the longest bold word ending index for each starting index in string s
            connect them if needed, to obatin the longest ending bold index      
            Form the result.
    
    Example:
        s = "aaabbcc"
        dict = ["aaa","aab","bc"]
        Output: 
        "<b>aaabbc</b>c"
*/

string addBoldTag(string &s, vector<string> &dict) 
{
    bool bold[s.size()] = {};
    for (int i = 0; i < s.size(); i++)
    {   
        int end = 0;

        for (auto & word : dict)    //find the longest bold word ending index, for each strting index in S
        {
            if (s.compare(i, word.size(), word) == 0) 
            {
                end = max(end, i + (int)word.size());
            }
        }
        bold[i] = (end > i);    //we only need to mark the longest string under bold
    }

    string result = "";
    for (int i = 0; i < s.length(); i++) 
    {
        if (!bold[i])   //if not bold, then simply keep on adding them to resultant array
        {
            result = result + s[i];
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