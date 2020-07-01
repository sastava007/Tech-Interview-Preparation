/*  Another solution: TC: O(N) where N is number of tasks
    If we are able to, somehow, determine the number of idle slots, we can find out the time required to execute all the tasks as (idle_slots + Total Number Of Tasks).
    
    The maximum number of idle slots will depend on task which has maximum no. of instances.
    Which is given by the product of the cooling time and the number of instances of the task with maximum (count - 1)

    Examples:
    AAAA BBB EE FF GG  & n = 3

    here X represents a space gap:
    Frame: "A[XXX]A[XXX]A[XXX]A"
    insert 'B': "ABXXABXXABXXA" <--- 'B' has higher frequency than the other characters, insert it first.
    insert 'E': "ABEXABEXABXXA"
    insert 'F': "ABEFABEXABFXA" <--- each time try to fill the k-1 gaps as full or evenly as possible.
    insert 'G': "ABEFABEGABFGA"

    Input:  ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
    Output: A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A   or  16 

*/

int leastInterval(vector<char>& tasks, int n) 
{
    vector<int> freq(26,0);
    for(char c: tasks)
        freq[c-'A']++;
    
    int max_val;
    sort(freq.begin(), freq.end());
    
    max_val = freq[25]-1;
    
    int idle_slots = max_val*n;
    
    for(int i=24; i>=0; i--)
        idle_slots -= min(freq[i], max_val);
    
    if(idle_slots>0)
        return idle_slots+tasks.size();
    else
        return tasks.size();
}


/*  Okay, so the first thing that jumps in my mind is to use somekind of greedy approach and to basically count the no. of instances of each task. Then we can start processing the one which
    has maximum instances. As we have to find the task with max instances so it sounds like using max heap.   

    And then basically we can enque all the tasks into the maxheap and keep on processing untill the queue not become empty. We can iterate till the cool down interval(n+1)
    and try to process the task. And everything which we just ran in temp.vector<> check if they still need to be processed and if yes then push them back into heap by decrementing their instance count 

    Time complexity : O(n). Number of iterations will be equal to resultant time.
    Space complexity : O(1). priority-queue and temp size will not exceed O(26).
 */

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        vector<int> map(26,0);        
        for(char c: tasks)
            map[c-'A']++;

        priority_queue<int> q;  //max-heap
        
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

/*  When execute in same order, and also maintainng the cool-down period 
    "AABB" & n=2 => A _ _ AB_ _ B  (8)
    "AB" & n=4 => AB (2)
    "ABAAB" & n=3 => AB _ _ A _ _ _ AB (10)
    "ACADBDD" & n=2 =>  A C _ A D B _ D _ _ D (11)
*/
int leastTime(string s, int n)
{
	unordered_map<char, int> m;
	int total = 0, timeRested = 0;
	
	for(int i=0; i<s.length(); i++)
	{
		int realTime = i+timeRested;
		if(m.find(s[i]) == m.end())
			m[s[i]] = realTime;
		else
		{
			int currentRest = 0;
			if(realTime - m[s[i]] <=n)
			{
				currentRest = n-(realTime-m[s[i]]-1);
				total += currentRest;
				timeRested += currentRest;
			}
			m[s[i]] = realTime+currentRest;
		}
		total++;
	}
	return total;
}