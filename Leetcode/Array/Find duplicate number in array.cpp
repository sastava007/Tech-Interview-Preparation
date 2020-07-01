/*  Using Floyd's Hare & Tortoise Cycle Detection Algorithm

    As all the no. are b/w 1-N & total number are N+1, so if we just start building a sequence from 1st element than each new element in seq. will be at index of prev. element
    If we start from X = nums[0], then nums[X] = Y, and next one will be nums[Y] = Z, so this way it continues untill we reach the same node again and hence a cycle get developed
    whose starting point is first duplicate element.

    Now we can use floy'd cycle detection algorithm, to find the entrance of that cycle.
    1st Step: hare moves twice as fast as tortoise, so it will first enter the cycle and meet tortoise at some point of intersection
    2d(tortoise) = d(hare)
    2(F+a) = F+nC+a,  so nC = F+a

    2nd Step: tortoise starts from beginning and hare from point of inters. so they'll meet at entrance of cycle. dist(tortoise) = F, wheras dist(hare) = cN+F => F

    Ex: [2,6,4,1,3,1,5]
               6
              /|
    2->4->3->1 |
              \5
              
*/

int findDuplicate(vector<int>& nums) 
{
    int tortoise = nums[0], hare = nums[0];

    do                              // Find the intersection point of the two runners.
    {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    }while(tortoise != hare);
    
    tortoise = nums[0];
    
    while(tortoise != hare)         // Find the "entrance" to the cycle.
    {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }
    return hare;
}


/* Using hash-Set, Time & Space: O(N) */
int findDuplicate(int[] nums) 
{
    unordered_set<int> seen;
    for (int num : nums) 
    {
        if (seen.find(num) != seen.end()) {
            return num;
        }
        seen.insert(num);
    }
    return -1;
}

/* Using sorting:
    TC: O(NlogN)  &  O(N) Space(if we can't modify the array, otheriwse constant)
*/

int findDuplicate(vector<int> &nums) 
{
    Arrays.sort(nums);
    for (int i = 1; i < nums.length; i++)
    {
        if (nums[i] == nums[i-1]) {
            return nums[i];
        }
    }
    return -1;
}