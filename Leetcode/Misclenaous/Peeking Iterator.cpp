/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}
	
	int peek() 
    {
        Iterator it(*this);     //  As here we only need to return the value at peek, instead of shifting the iterator. So it's better to create another object of iterator and call it's next,
                                // so that new object peeking iterator get shifted instead of shifting our original one.
        return it.next();
	}

	int next() 
    {
	    return Iterator::next();
	}
	
	bool hasNext() const 
    {
	    return Iterator::hasNext();
	}
};