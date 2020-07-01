/*      Given three unsorted list of numbers. Write function that will return next minimum element out of these lists (remove that element from list)

        1. Sort each list, and add the first element of each list, and list number to a min-heap ```n1 log n1 + n2 log n2 + n3 log n3 + 3 log 3```
        2. Then check if min-heap is empty or not O(1)
        3. next(): extract min-heap from the list, and add the next number from the same list (n1 + n2 + n3 )log 3 which is equivalent to O(n1+n2+n3)

        Space: O(3) as we're only storing 3 elements in our heap

        Input: list1 = [5, 1, 2, 4], list2 = [4, 6, 3], list3 = [9, 0, 7]
        while(hasNext())
            cout<<next();
        [0,1,2,3,4,4,5,6,7,9] 
*/

class Solution
{
    public:
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    void init(vector<list<int>> v)
    {
        if(!v[0].empty())  {    // if list is already sorted then skip sorting it, and directly add first element from each list
            v[0].sort();
            q.push({v[0].front(), 0});
            v[0].pop_front();
        }

        if(!v[1].empty())  {
            v[1].sort();
            q.push({v[1].front(), 1});
            v[1].pop_front();
        }

        if(!v[2].empty())  {
            v[2].sort();
            q.push({v[2].front(), 2});
            v[2].pop_front();
        }
    }
    int next()
    {
        auto temp = q.top();
        q.pop();

        int k = temp.second;
        if(!v[k].empty())
        {
            q.push({v[k].front(), k});
            v[k].pop_front();
        }
        return temp.first;
    }
    
    bool hasNext()
    {
       return (q.size() != 0);
    }
}