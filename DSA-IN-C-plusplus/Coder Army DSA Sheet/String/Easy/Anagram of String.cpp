

// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2){
    // Your code goes here
    unordered_map<char, int>mp;
    
    for(int i=0; i<str1.size(); i++){
        mp[str1[i]]++;
    
    }
    
    for(int i=0; i<str2.size(); i++){
        mp[str2[i]]--;
    }
    
    int ans = 0;
    
    for(auto i: mp){
        ans += abs(i.second);
    }
    
    return ans;
}
