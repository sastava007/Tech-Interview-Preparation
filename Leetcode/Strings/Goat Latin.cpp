/*  Simple solution, just convert what's given in language to code 
    O(N) TC where N is length of string S
*/

string toGoatLatin(string S) 
{
    unordered_set<char> vowel({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
    istringstream iss(S);
    string res, w;
    int i = 0, j;
    while (iss >> w)
    {
        res += ' ' + (vowel.count(w[0]) == 1 ? w : w.substr(1) + w[0]) + "ma";
        for (j = 0, ++i; j < i; ++j)
            res += "a";
    }

    return res.substr(1);
}

/* Another Solution */
class Solution {
private:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    string toGoatLatin(string S) {
        istringstream ss(S);
        string word, ans;
        string suffix = "a";
        while (ss >> word) {
            if (!isVowel(word[0])) rotate(word.begin(), word.begin() + 1, word.end());
            ans += (suffix.size() > 1 ? " " : "") + word + "ma" + suffix;
            suffix += "a";
        }
        return ans;
    }
};