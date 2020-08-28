/*  
    Constant O(1) space

    Input: "the sky is blue"
    Output: "blue is sky the"

    First reverse the entire string, then traverse through the string and reverse back the individual words

*/

string reverseWords(string s) 
{
    int i=0, j=0, startIndex = 0, n=s.length();
    
    reverse(s.begin(), s.end());
    while(i<n)
    {
        if(s[i] != ' ')
        {
            if(startIndex != 0)
                s[startIndex++] = ' ';
        
            j = i;
            while(j<n && s[j] != ' ')
                s[startIndex++] = s[j++];
            reverse(s.begin() + startIndex - (j-i), s.begin()+startIndex);
            i = j;
        }
        
        i++;
    }
    return s.substr(0, startIndex);
}

// Using extra space, i.e first parse the input string and extract all the words inside a vector and later combine them
string reverseWords(string s) 
{
    while(*s.begin()==' ')
        s.erase(0, 1);
    
    while(*(s.end()-1)==' ')
        s.pop_back(); 
    
    int i=0, n = s.length();
    string result = "";
    bool wordFound = false;
    
    while(i<n)
    {
        string temp = "";
        while(i<n && s[i] != ' ')
        {
            temp += s[i++];
            wordFound = true;
        }
        if(wordFound)
            result = " " + temp + result;
        i++;
        wordFound = false;
    }
    
    if(result != "")
        result.erase(0,1);
    return result;
}