/*  Given a list, whose elements are either integers or other lists. Implement an iteraor to flatten it.
    
    Note: We're assuming that, next() will be called repeatedly untill hasNext() is true. 

    Ex: [1,[4,[6,3]],5] => [1,4,6,3,5]

    TC: O(N) and Space: O(depth of nesting) which in worst case becomes N when there is no nesting ex: [1,4,2,3]
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
