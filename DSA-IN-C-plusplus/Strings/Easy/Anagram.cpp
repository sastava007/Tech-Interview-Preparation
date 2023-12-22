class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
      bool isAnagram(string a, string b){
        
        // Your code here
        // sort(a.begin(),a.end());
        // sort(b.begin(),b.end());
        // return a==b;
        
        
        if(a.size()!=b.size())return false;
        int count[26]={0};
        for(int i=0;i<a.size();i++){
            count[a[i]-'a']++;
            count[b[i]-'a']--;
        }
      
        for(int i=0;i<26;i++)
          {
              if(count[i])return false;
          }
          return true;
        
        
    }

};
