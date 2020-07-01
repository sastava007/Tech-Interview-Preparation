/* 
    Intution: say we have the numbers 1, 5, 2 easiest solution is to construct the following array
    arr[] = {0,1,1,1,1,1,2,2}
    then generate a random number between 0 and 7 and return the arr[rnd]. This solution is not really good though due to the space requirements.

    The solution here is similar but instead we construct the following array (accumulated sum). We can generate random number in range [1, maxsum]
    {1, 6, 8} So if we generated number is up to 1 is index 0. all numbers generated greater than 1 and up to 6 are index 1 and all numbers greater than 6 and up to 8 are index 2. After we generate a random number to find which index to return we use binary search.

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
    
    int pickIndex() 
    {
        int m = s.back();
        int r = (rand() % m) + 1;   // this will generate random no. in between [1,8] inclusive, now all we need is to get the position for this value using binary_search(lower bound)
        int index = lower_bound(r);
        return index;
    }

    int lower_bound(int x)
    {
        int low = 0, high = s.size()-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(x > s[mid])
                low = mid+1;
            else
                high = mid-1;
        }
        return low;
    }
};