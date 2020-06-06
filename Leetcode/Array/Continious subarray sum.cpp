/* Using set, idea is to delay insertion of presum by using pre variable to ensure that length is >1 */

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        unordered_set<int> s;
        
        int pre = 0, sum = 0;
        for(auto it: nums)
        {
            sum += it;
            
            if(k != 0)
                sum %= k;
            
            if(s.find(sum) != s.end())
                return true;
            
            s.insert(pre);
            pre = sum;
        }
        
        return false;
    }
};

/* Using map to store index */

class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int sum = 0;
        //key : number(k modular result)
		//value : index (for calculating distance from now position!!!)
        Map<Integer, Integer> map = new HashMap<Integer, Integer>(){{
            put(0,-1);
        }};
        for(int i=0; i<nums.length; i++) {
            sum = sum + nums[i];
            if(k != 0) sum = sum % k;

            //if sum number exist in map, 
            //now position's value minus sum in map equals 0 !!! It means that the array can make k with the subarray!!!
            if(map.containsKey(sum)) {
                int distance = i - map.get(sum);
                if(distance > 1) return true;
            } else {
                map.put(sum, i);
            }
        }
        return false;
    }
}