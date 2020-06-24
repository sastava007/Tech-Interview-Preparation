/*  Find the K most frequent words
    Here answer is sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.
    As we've to find the K most frequent occuring elements, then this looks similar to finding K larget elemenets using a min-heap. And later, return the result after reversing

    TC: O(NlogK) and Space: O(N) 
 */

class Solution {
    
    class compare{      // custom comparator for min-heap
    public:
        bool operator()(pair<string,int> a, pair<string,int> b)
        {
            return (a.second > b.second || (a.second == b.second && a.first < b.first));
        }
    };
    
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string, int> freq;
        for(string word: words)
            freq[word]++;
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, compare> q;    // here we're building min-heap
        
        for(auto it: freq)
        {
            q.push({it.first, it.second});      // here instead of directly pushing & popping, we can first check if our curr freq is > than that at the top of priority_queue
            if(q.size()>k)
                q.pop();
        }
        
        //At this point priority_queue will have K most frequent elements, but their order will be opposite. The element at front() will be having smallest freq among all K, so reverse the result
        vector<string> result;
        
        while(!q.empty())
        {
            result.emplace_back(q.top().first);
            q.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

/*  
    We can also use threshold frequency i.e Kth most frequent element, and then filter all the words which have frquency >= threshold and later sort the result using additional O(KlogK) 
    TC: O(N + O(klogK)) Avg Case, but worst case O(N^2)
    Space: O(N)
*/