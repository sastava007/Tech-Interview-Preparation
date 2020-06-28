/*  Instead of processing all 20000 people, we can process pairs of (age, count) representing how many people are that age.
    Since there are only 120 possible ages, this is a much faster loop. 

    Ex: [16,17,18]   O/P: 17 -> 16, 18 -> 17.
        [20,30,100,110,120]    O/P: 110 -> 100, 120 -> 110, 120 -> 100   
*/

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        
        vector<int> hash(121,0);
        for(int it: ages)
            hash[it]++;

        int request=0;

        for(int a=1; a<=120; a++)
            for(int b=1; b<=120; b++)
            {
                if(b>a || b<=0.5*a+7)
                    continue;

                if(a==b)
                    request += hash[a]*(hash[a]-1); //if both has same age, then send everyone except itself, so that's why hash[a]-1
                else
                {
                    request += hash[a]*hash[b];
                }

            }

        return request;
        
    }
};