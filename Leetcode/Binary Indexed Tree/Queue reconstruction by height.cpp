/* 
    We can make another array of length N, the number K means that we should put this person at the Kth empty position from the beginning. The empty position mean that there will be higher
    or equal height person coming in here, so leave these positions out first. For everyone, we should first insert the lower h person.

    TC: O(N^2)

    input: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
    sort:  [[4,4], [5,2], [5,0], [6,1], [7,1], [7,0]]

    step1: [[ , ], [ , ], [ , ], [ , ], [4,4], [ , ]]
    step2: [[ , ], [ , ], [5,2], [ , ], [4,4], [ , ]]
    step3: [[5,0], [ , ], [5,2], [ , ], [4,4], [ , ]]
    step4: [[5,0], [ , ], [5,2], [6,1], [4,4], [ , ]]
    step5: [[5,0], [ , ], [5,2], [6,1], [4,4], [7,1]]
    step6: [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

*/

class Solution {

    static bool comp(const vector<int> &a, const vector<int> &b)
    {
        return (a[0]<b[0] || a[0]==b[0] && a[1]>b[1]);
    }
    
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        sort(people.begin(), people.end(), comp);
        vector<vector<int>> res(people.size(), vector<int>());
        
        for(auto ppl: people)
        {
            int count=0,j;
            for(j=0; j<res.size(); j++)
            {
                if(res[j].empty())
                {
                    if(count==ppl[1])
                        break;
                    count++;
                }
            }
            res[j] = ppl;
        }
        
        return res;
    }
};

/* We can optimize it using BIT, to find the Kth empety position so TC will become O(NlogN) */