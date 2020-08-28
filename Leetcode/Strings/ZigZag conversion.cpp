/* 
    Given a string, print the string in zigzag fashion in given N rows. 

    Input = "PAYPALISHIRING" and N = 3   Output = "PAHNAPLSIIGYIR"
        
    P   A   H   N
    A P L S I I G
    Y   I   R
    
*/

string convert(string s, int numRows) 
{
    if(numRows == 1)
        return s;
    
    vector<string> v(min(numRows, int(s.size())));  // To avoid empty strings, when numRows > string length
    
    int currRow = 0;
    bool down = false;
    for(char c: s)
    {
        v[currRow] += c;
        if(currRow==0 || currRow ==numRows-1)
            down = !down;
        if(down)
            currRow++;
        else
            currRow--;
    }
    
    string res;
    for(string row: v)
    res += row;
                        
    return res;
}

/* Without using extra space */
string convert(string s, int numRows) 
{
    if (numRows == 1) return s;

    string ret;
    int n = s.size();
    int cycleLen = 2 * numRows - 2;

    for (int i = 0; i < numRows; i++) 
    {
        for (int j = 0; j + i < n; j += cycleLen) 
        {
            ret += s[j + i];
            if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                ret += s[j + cycleLen - i];
        }
    }
    return ret;
}