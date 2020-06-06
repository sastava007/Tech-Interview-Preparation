/*  The words are sorted lexicographically if and only if adjacent words are. This is because order is transitive: a <= b and b <= c implies a <= c. 
    Time Complexity: O(NS) where N is total number of word in words[] and S is maximum length size of word
*/

class Solution {
    
public:
    
    bool isAlienSorted(vector<string>& words, string order) 
    {   
        vector<int> hash(26);
        for(int i=0; i<order.length(); i++)
            hash[order[i]-'a']=i;
        
        for(int i=0; i<words.size()-1; i++)
        {
            string word1=words[i];
            string word2=words[i+1];
            
            if(!isSmaller(word1, word2, hash))  //if word1 is not smaller than word2 then return false, else continue
                return false;
        }
        
        return true;
    }
               
    bool isSmaller(string word1, string word2, vector<int> &hash)
    {
            for(int i=0; i<min(word1.length(), word2.length()); i++)    //for two words two be lexogriphacally sorted, only check for first not equal charcter and leave other. ex: (azyx < b)  
                if(word1[i] != word2[i])
                    return (hash[word1[i]-'a'] < hash[word2[i]-'a']);
    
            return (word1.length()<word2.length()); //if we havn't find any different character, like (app & apple)
    }
};