/* 
    Intution: say we have the numbers 1, 5, 2 easiest solution is to construct the following array
    arr[] = {0,1,1,1,1,1,2,2}
    then generate a random number between 0 and 7 and return the arr[rnd]. This is solution is not really good though due to the space requirements.


    The solution here is similar but instead we construct the following array (accumulated sum). We can generate random number in range [1, maxsum]
    {1, 6, 8} So if we the random generated number as lets say
    [upto 1] -> 0
    (1, 6] -> 1
    (6, 8 -> 2

    After we generate a random number to find which index to return we use binary search or lower_bound

 */

class Solution {
public:
    vector<int> s;
    Solution(vector<int> w) 
    {
        for (int i : w)     //cumulative sum
            s.push_back(s.empty() ? i : (i + s.back()));
        
        srand(time(NULL));
    }
    
    int pickIndex() {
        int m = s.back();
        int r = rand() % m;
        auto it = lower_bound(s.begin(), s.end(), r+1);
        return it - s.begin();
    }
};