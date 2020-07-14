/*  Given a list, whose elements are either integers or other lists. Implement an iteraor to flatten it.
    
    Clarrifying ques to ask?
        1. Do we've to just return a flatten form of list as a vector or one element at a time?

    Note: We're assuming that, next() will be called repeatedly untill hasNext() is true. 
    Ex: [1,[4,[6,3]],5] => [1,4,6,3,5]

    TC: Amortized O(1) per query, but we need to process each element before we can return & there are N elements.
    O(N) and Space: O(depth of nesting) which in worst case becomes N when there is no nesting ex: [1,4,2,3]

 */

class NestedIterator {
private:
    stack<NestedInteger> todo;
public:
    NestedIterator(vector<NestedInteger> &nestedList) 
    {
        int size = nestedList.size();
        
        for(int i=size-1; i>=0; i--)
            todo.push(nestedList[i]);
    }
    
    int next() 
    {
        NestedInteger curr = todo.top();
        todo.pop();
        return curr.getInteger();
    }
    
    bool hasNext()  
    {
        while(!todo.empty())  // it is basically responsible for parsing the list and make sure that top of stack always holds an integer. This will keep on parsing untill it encounters an integer
        {
            NestedInteger curr = todo.top();
            if(curr.isInteger())
                return true;
        
            todo.pop();
            vector<NestedInteger> adjs = curr.getList();
            int size = adjs.size();
            for(int i = size - 1; i >= 0; i--)
                todo.push(adjs[i]);
        }
        return false;
    }
};

/* Using Iterators & Pointers: A fancy solution without using Stack & Recursion */
class NestedIterator {
private:
    vector<NestedInteger>::iterator current, last;
    shared_ptr<NestedIterator> iter;
    
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        current = nestedList.begin();       // points to the first element of nested List
        last = nestedList.end();           // points to the last element of nested List
        iter = nullptr;
    }

    int next() 
    {
        int data;
        if (current->isInteger())
        {
            data = current->getInteger();
            current++;
        }
        else
        {
           data = iter->next();
        }
        return data;
    }

    bool hasNext() 
    {
        if (current ==  last)   //represent we've reached end of list
        {
            return false;
        }
        while(current != last)
        {
            if (current->isInteger())
            {
                return true;
            }
            else
            {
                iter = iter == nullptr ? make_shared<NestedIterator>(current->getList()): iter;
                if (iter->hasNext())
                {
                    return true;
                }
                else
                {
                    current++;
                    iter = nullptr;
                }
            }
        }
        return false;
    }
};

/* Using Recursion, without using Stack */
public class NestedIterator implements Iterator<Integer> {

    private List<Integer> mList = new ArrayList<>();
    private int index = 0;

    public NestedIterator(List<NestedInteger> nestedList) {
        for(int i=0;i<nestedList.size(); i++){
            flatten(nestedList.get(i));
            index = 0;
        }

    }

    private void flatten(NestedInteger ni){     //recursive function
        if(ni.isInteger()){
            mList.add(ni.getInteger());
        }else{
            for(NestedInteger i : ni.getList()){
                flatten(i);
            }
        }
    }

    public Integer next() {
        return mList.get(index++);
    }

    public boolean hasNext() {
        return index < mList.size();
    }
}