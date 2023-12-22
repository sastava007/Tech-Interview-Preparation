//User function Template for C++
class Solution
{
    public:
    string reverseWord(string str)
    {
        // Your code goes here
        
        string s="";
        for(int i=str.size(); i>=0; i--){
            s += str[i]; 
        }
        
        return s;
    }
};

// Solution 2

//User function Template for C++
class Solution
{
    public:
    string reverseWord(string str)
    {
        // Your code goes here
        
        
        int i=0, j = str.size()-1;
        while(i<=j){
            swap(str[i], str[j]);
            i++;
            j--;
        }
        
        return str;
    }
};


// Solution 3

//User function Template for C++
class Solution
{
    public:
    string reverseWord(string str)
    {
        // Your code goes here
        int n = str.size();
        
       for(int i=0; i<n/2; i++){
           
           swap(str[i], str[n-i-1]);
           
       }
       
       return str;
    }
};
