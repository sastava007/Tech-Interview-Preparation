
class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here
        string temp="";
        string result="";
        for(int i=S.size()-1; i>=0; i--){
            if(S[i]=='.'){
                temp=temp+S[i];
                result=result+temp;
                temp="";
            }
            
            else{
                temp = S[i]+temp;
            }
        }
        
        result=result+temp;
        return result;
    } 
};
