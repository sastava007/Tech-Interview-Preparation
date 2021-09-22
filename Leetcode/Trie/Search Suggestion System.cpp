/* 
    Given an array of strings products and a string searchWord. Design a system that suggests atmost 3 product names after each character of searchWord is typed.
    If there are more than three products with a common prefix return the three lexicographically minimum products.
*/

/* 
    As we need to find lexicographically 3 smallest products, so we can sort the products, and then we can do a binary search for prefix. Once we locate the first match
    for prefix, all we need to do is to find the next 3 words in products (if any) and add it to list of suggeted products.

    TC: O(NlogN) for sorting + O(mlogN) for binary search and O(m*mlogN) considering the find operation as well. Where N is total #products (and, stricter - characters).
    So final complexity = O(nlogN + m*mlogN) Since N dominates over m*m So TC: O(NlogN)

    Space: O(1) => assuming in-place sort otherwise O(logN) for quick sort and we're not considering space for output
*/
vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
{
    sort(products.begin(), products.end());
    auto it = products.begin();
    
    string curr;
    vector<vector<string>> res;
    for(char c: searchWord)
    {
        curr += c;
        vector<string> suggested;
        it = lower_bound(it, products.end(), curr);
        for(int i=0; i<3 && (it+i)!=products.end(); i++)
        {
            string s = *(it+i);
            if(s.find(curr))
                break;
            suggested.emplace_back(s);
        }
        res.emplace_back(suggested);
    }
    return res;
}

/* Trie */