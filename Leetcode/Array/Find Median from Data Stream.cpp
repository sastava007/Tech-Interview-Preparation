/* 
    1. Naive: Sort each time we need to query median.  TC: O(1) for insertion and O(nlogn) for each median query
    2. Using insertion sort, we can maintain our container always sorted.  TC: O(N) for insertion and O(1) for each median query
    3. Using two heaps, TC: O(5logn) => O(logn) for insertion and O(1) for query, Space: O(N)
*/

/*  Balancing Step:
    As max-heap (low) stores the smaller half no, so we need to remove the largest element while balancing.
    Similarly min-heap(high) stores the larger half no. so we need to remove the smallest element and add it to other 
 */

class MedianFinder {
    
private:
    priority_queue<int> low;    // max heap - stores the smaller half element
    priority_queue<int, vector<int>, greater<int>> high;    // min heap - stores the larger half elements
    
public:
    /*
        1. First add the no. to max_heap low, since a new element is added to low, so we must do a balancing step for high. So remove the largest element from low and add it to high.
        2. The min-heap high might end holding more elements than max-heap low, after the previous operation. We fix that by removing the smallest element from high and adding it to low.
    
    */
    void addNum(int num) 
    {
        low.push(num);      // add it to max-heap
        
        high.push(low.top());       // balance min-heap, by adding the newly inserted element to it
        low.pop();

        if(high.size()>low.size())  // if size of min-heap become greater than max-heap
        {
            low.push(high.top());
            high.pop();
        }
    }
    
    double findMedian() 
    {
        return low.size()>high.size()?low.top():(double)(low.top()+high.top())/2;    
    }
};


/* Using multiset - one iterator TC: O(logn) and O(1) */
class MedianFinder {
    multiset<int> data;
    multiset<int>::iterator mid;

public:
    MedianFinder()
        : mid(data.end())
    {
    }

    void addNum(int num)
    {
        const int n = data.size();
        data.insert(num);

        if (!n)                                 // first element inserted
            mid = data.begin();
        else if (num < *mid)                    // median is decreased
            mid = (n & 1 ? mid : prev(mid));
        else                                    // median is increased
            mid = (n & 1 ? next(mid) : mid);
    }

    double findMedian()
    {
        const int n = data.size();
        return ((double) *mid + *next(mid, n % 2 - 1)) * 0.5;
    }
};