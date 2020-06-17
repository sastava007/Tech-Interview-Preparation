class NestedInteger 
{
    public:
      bool isInteger() const;
      int getInteger() const;
      const vector<NestedInteger> &getList() const;
};

class Solution {
public:
    int depthSum(const vector<NestedInteger>& nestedList) 
    {
        return dfs(nestedList, 1);
    }
private:
    int dfs(const vector<NestedInteger>& nestedList, int depth)
    {
        if(nestedList.size()==0)
            return 0;
        int sum =0;
        for(auto it: nestedList)
        {
            if(it.isInteger())
                sum += (it.getInteger()*depth);
            else
            {
                sum += dfs(it.getList(), depth+1);
            }
        }
        return sum;
    }

    int bfs(const vector<NestedInteger>& nestedList) 
    {
        queue<pair<NestedInteger, int>> Q;  //here second parameter represents depth
        for (auto ni : nestedList) {
            Q.push({ni, 1});
        }
        // level order bfs
        int sum = 0;
        while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            if (cur.first.isInteger()) {
                sum += cur.first.getInteger() * cur.second;
            } else {
                // add subtree to st
                for (auto next : cur.first.getList()) {
                    Q.push({next, cur.second + 1});
                }
            }
        }
        return sum;
    }
};

/* Nested List Weight Sum 2: Here weight is defined from bottom to up. The leaf level integers have weight 1 and root level have largest weight  */

class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int depth = getDepth(nestedList);
        return helper(nestedList, depth);
    }

private:
    int getDepth(vector<NestedInteger>& nestedList) {   //this will give the maximum depth of list
        int depth = 0;
        for (auto& nestedInt : nestedList) {
            if (nestedInt.isInteger()) {
                depth = max(depth, 1);
            } else {
                depth = max(depth, 1 + getDepth(nestedInt.getList()));
            }
        }

        return depth;
    }

    int helper(vector<NestedInteger>& nestedList, int depth) {
        int sum = 0;
        for (auto& nestedInt : nestedList) {
            if (nestedInt.isInteger()) {
                sum += depth * nestedInt.getInteger();
            } else {
                sum += helper(nestedInt.getList(), depth - 1);
            }
        }

        return sum;
    }
};