/*  
    Using Sample Reservoir concept: O(1) space 
    [1,2,3,3,3] & target = 3, so idea is to maintain counter of target value. 
    When we have just ecncountered 3 for the first time, then probability of selecting index 2 is => 1 (coz that's the only occurence we've met so far)
    When counter = 2, we have 2 options to select from[2,3], so probablity of selecting any one from them will be 1/2
    Similarly when we counter = 3, we've 3 options to select from [2,3,4]. So the probability of selecting any one from them will be 1/3

    2: Prob to pick 2 => 1
    3: Prob to pick 3 => 1/2 and Prob to pick 2 => 1/2
    4: Prob to pick 4 => 1/3 and Prob to pick [2,3] => 2/3

    Total Probability to pick 2: 1*1/2*2/3 => 1/3
    Total Probability to pick 3: 1/2*2/3 => 1/3
    Total Probability to pick 4: 1/3 => 1/3
*/

class Solution {
private:
    vector<int> num;
public:
    Solution(vector<int>& nums) 
    {
        num=nums;
        srand(time(NULL));
    }
    int pick(int target) 
    {
        int index, counter=0;   //counter stores the number of times target has occurred
        for(int i=0; i<num.size(); i++)
        {
            if(target==num[i])
            {
                counter++;
                if(rand()%counter==0)   //if counter=1, means first time then definitely rand()%counter=0 and current index will be stored
                    index=i;
            }
        }
        return index;
    }
};


/* 
    A simple solution is to put indices of all numbers that are equal to target in the vector<>
    and then then randomly return any one of the index from it.

    O(N) Space: O(N) time
*/

class Solution {
    vector<int>arr;
public:
    Solution(vector<int>& nums) {
        arr = nums;
        srand(time(NULL));
    }
    
    int pick(int target) 
    {
        vector<int>ans;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i] == target)
                ans.push_back(i);
        }
        
        return ans[rand()%ans.size()];
    }
};
