//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        map<char, int>mpp;
        for(int i=0; i<str.size(); i++){
            mpp[str[i]]++;
        }
        
        int mx=0, ans;
        for(auto it: mpp){
            if(it.second > mx){
                ans = it.first;
                mx = it.second;
            }
        }
        
        return ans;
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends
