/* 
    Decode the k[encoded_string], where encoded_string inside the bracket is being repeated exactly K times.
    Ex: "3[a]2[bc]"  Output: "aaabcbc"
    These are invalid input: 3a or 2[4]

    TC & Space: O(N)
*/

string decodeString(string a) 
{
    stack<string> s;
    for(int i=0; i<a.length(); i++)
    {
        if(a[i]==']')
        {
            string temp="", ans="";
            while(!s.empty() && s.top()!="[")
            {
                temp=s.top()+temp;
                s.pop();
            }
            if(!s.empty())  //remove that opening bracket, if stack hasn't been empty yet.
                s.pop();
        
            int num=0, p=1;
            while (!s.empty() && isdigit(s.top()[0]))      // after removing the opening bracket, we are guranteed to have a number
            {
                num = stoi(s.top())*p + num;
                p*=10;
                s.pop();
            }
            for(int j=0;j<num;j++)
                ans+=temp;
            
            s.push(ans);    
        }
        else
        {
            string x(1,a[i]);   // to convert char to string
            s.push(x); 
        }
    }
    string ans="";
    while(!s.empty())
    {
        ans = s.top() + ans;
        s.pop();
    }
    return ans;
}

/*  Recursive Approach
    Every time we meet a '[', we treat it as a subproblem so call our recursive function to get the content in that '[' and ']'. After that, repeat that content for 'num' times.
    Every time we meet a ']', we know a subproblem finished and just return the 'word' we got in this subproblem.
*/

string decodeString(string s) 
{
    int pos = 0;
    return helper(pos, s);
}
string helper(int &pos, string s)
{
    int num=0;
    string word = "";
    for(;pos<s.size(); pos++)
    {
        char cur = s[pos];
        if(cur == '[')
        {
            string curStr = helper(++pos, s);
            while(num--)
                word += curStr;
        } else if (cur >= '0' && cur <='9')     // if digits
        {
            num = num*10 + cur - '0';
        }
        else if (cur == ']')
        {
            return word;
        }
        else    // Normal characters
        {    
            word += cur;
        }
    }
    return word;
}