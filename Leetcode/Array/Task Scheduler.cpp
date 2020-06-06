/*  Okay, so the first thing that jumps in my mind is to use somekind of greedy approach and to basically count the no. of instances of each task. Then we can start processing the one which
    has maximum instances. As we have to find the task with max instances so it sounds like using max heap.   

    And then basically we can enque all the tasks into the maxheap and keep on processing untill the queue not become empty. We can iterate till the cool down interval(n+1)
    and try to process the task. And everything which we just ran in temp.vector<> check if they still need to be processed and if yes then push them back into heap by decrementing their instance count 

    Time complexity : O(n). Number of iterations will be equal to resultant time.
    Space complexity : O(1). queuequeue and temptemp size will not exceed O(26).
 */

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        vector<int> map(26,0);
        
        for(char c: tasks)
            map[c-'A']++;
        
        priority_queue<int> q;
        
        for(int i=0; i<26; i++)
            if(map[i]>0)
                q.push(map[i]);
        
        int cycles=0;
        while(!q.empty())
        {
            vector<int> temp;
            for(int i=0; i<n+1; i++)
            {
                if(!q.empty())
                {
                    temp.push_back(q.top());
                    q.pop();
                }
            }
            
            for(int it: temp)   //decrease one instances of each task, as we have processed it one time
                if(--it>0)      // if still needs to be processed then push it again into the queue
                    q.push(it);
            
            cycles += q.empty()?temp.size():n+1;
        }
        
        return cycles;
            
    }
};


/*  Another solution: TC: O(N) where N is number of tasks
    If we are able to, somehow, determine the number of idle slots, we can find out the time required to execute all the tasks as idle_slots + Total Number Of Tasks.
    The maximum number of idle slots will always be given by the product of the cooling time and the number of instances of the task with maximum count - 1

    Maximum no. of idles lots will depend on the task which has maximum number of instanes

    Examples:

    AAAABBBEEFFGG 3

    here X represents a space gap:

    Frame: "A[XXX]A[XXX]A[XXX]A"
    insert 'B': "ABXXABXXABXXA" <--- 'B' has higher frequency than the other characters, insert it first.
    insert 'E': "ABEXABEXABXXA"
    insert 'F': "ABEFABEXABFXA" <--- each time try to fill the k-1 gaps as full or evenly as possible.
    insert 'G': "ABEFABEGABFGA"

*/

public class Solution 
{
    public int leastInterval(char[] tasks, int n) {
        int[] map = new int[26];
        for (char c: tasks)
            map[c - 'A']++;
        Arrays.sort(map);
        int max_val = map[25] - 1, idle_slots = max_val * n;
        for (int i = 24; i >= 0 && map[i] > 0; i--) 
        {
            idle_slots -= min(map[i], max_val);
        }
        return idle_slots > 0 ? (idle_slots + tasks.length) : tasks.length;
    }
}