/*  
    TC: O(N) & Space: O(1)

    Input: "the sky is blue"
    Output: "blue is sky the"

    Idea is to start iterating from backwards, and once we get a string we'll reverse it before appending it to result
*/

string reverseWords(string s) 
{   
    string result;
    int i = (int)s.size()-1;
    while(i >= 0)
    {
        while(i >= 0 && s[i] == ' ')    // skip all the leading & trailing whitespaces
            i--;
        string temp = "";
        while(i >= 0 && s[i] != ' ')    // append characters to get the word
            temp += s[i--];
        
        if(temp != "")    // only add the words/ string which are non empty
        {
            reverse(temp.begin(), temp.end());
            result += (temp + " ");
        }
    }
    result.pop_back();  // there is atleast 1 word in string, that's why we can perform pop_back without checking
    return result;
}

/* Using extra space, i.e first parse the input string and extract all the words inside a vector and later combine them */

string reverseWords(string s) 
{
    vector<string> v;
    string result;
    int i = 0;
    while(i< s.size())
    {
        while(i<s.size() && s[i] == ' ')    // skip all the leading & trailing whitespaces
            i++;
        string temp = "";
        while(i<s.size() && s[i] != ' ')    // append characters to get the word
            temp += s[i++];
        
        if(temp!="")    // only add the words/ string which are non empty
            v.push_back(temp);
    }
    
    for(int i = (int)v.size()-1; i>=0; i--)  // no need to explicitly reverse, instead iterate from backwards
    {
        result += v[i];
        if(i != 0)
            result += " ";
    }
    return result;
}