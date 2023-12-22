
class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        if(s1.size() != s2.size()){
            return false;
        }
        
        else{
            s1 = s1 + s1;
            return (s1.find(s2) !=  -1) ? true: false;
        }
    }
};
