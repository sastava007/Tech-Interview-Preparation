/*      
    Discrete Binary Search
    TC: O(NlogW) where N is no. of piles and W is size of largest pile

    If Koko can finish eating all the bananas (within H hours) with an eating speed of K, she can also finish with a larger speed too so we need to reduce it's speed so that she enjoy's the 
    process.

    There is a limited range of K's to enable her to eat all the bananas within H hours.
    We need to reduce the searching space for the discrete values of K, and to return the minimum valid K.
    
    Example: piles = [3,6,7,11], H = 8  answer = 4
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) 
    {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        
        while(low<=high)
        {
            int k = low+(high-low)/2;
            if(canEatAll(piles, H, k))
                high = k-1;
            else
                low = k+1;
        }
        return low;
    }
    
private:
    bool canEatAll(vector<int>& piles, int H, int k)
    {
        int totalHour = 0;
        for(int pile: piles)
        {
            totalHour += ceil((float)pile/k);
        }
        
        return (totalHour <= H);
    }
};