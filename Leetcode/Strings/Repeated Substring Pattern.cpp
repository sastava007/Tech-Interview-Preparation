/* 
    Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
    Ex: "abab" can be constructed by appending "ab" 1 time
*/

/* Trivial Solu: TC: O(N * rootN) The root factor comes into picture becz a no. have atmost sqrt(N) factors */
bool repeatedSubstringPattern(string s) 
{
    for(int i=s.size()/2; i>=1; i--)    // the no. of factors will be bounded by O(sqrtN)
    {
        if(s.size()%i==0)
        {
            string chunk = s.substr(0, i);
            string temp;
            for(int j=0; j<s.size()/i; j++)
                temp += chunk;
            if(temp == s)
                return true;
        }
    }
    return false;
}

/* 
    Clever solution: Append the string to original string itself and then delete first and last char. And still if original string exist then there exists a pattern.
    If string can't be subdivided it will be represented as a single lego block. Whereas if its made of repeated sub strings it can made using smaller lego blocks in a train like fashion.

    take an example of a string made of 3 lego blocks .. now if you double the string the total string consists of 6 lego block. label them 1 to 6 .. if you look closely if we 
    remove blocks 1 and 6. you will still be able to recover the original string using block 2 3 and 4. this construction wont be possible if your string is made of only 1 block.

    Average TC: O(N)
    Worst Case would be when search contains a lot of long partial matches
    TC: O(N*M) where M is length of original substring to optimize this we should use KMP
*/

bool repeatedSubstringPattern(string s) 
{
    string temp = s+s;
    temp = temp.substr(1, s.size()*2-2);
    return temp.find(s) != -1;
}