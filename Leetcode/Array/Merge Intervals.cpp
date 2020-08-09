/*  
    We are given a collection of intervals, merge all overlapping intervals.
    Using sorting: O(nlogn) complexity
    Input: [[1,3],[2,6],[8,10],[15,18]]  Output: [[1,6],[8,10],[15,18]]
*/

class Solution
{
public:
    static bool comp(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> merged;

        if (intervals.size() == 0)
            return merged;

        sort(intervals.begin(), intervals.end(), comp);
        merged.emplace_back(intervals[0]);

        for (int i = 1; i < intervalvs.size(); i++)
        {
            int n = merged.size();
            if (intervals[i][0] <= merged[n - 1][1]) //If staring of current interval is smaller or equal than ending of our previous one, then it will be touch/intersect each other so merge them
                merged[n - 1][1] = max(intervals[i][1], merged[n - 1][1]);
            else
                merged.emplace_back(intervals[i]);
        }
        return merged;
    }
};

/* Follow Up:   How do you add intervals and merge them for a large stream of intervals, basically you don't have access to all the intervals in beginning and they keep on coming with time
                in form of the stream?
*/

// Approach 1 : We can use a priority queue here. As we have an incoming stream of intervals, we just need to keep them sorted and pop the smallest two intervals and check 
// if we can merge them.to keep them sorted, use a min - heap() build on starting value of interval.

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < intervals.size(); i++)
        pq.push({intervals[i][0], intervals[i][1]});

    vector<vector<int>> ans;
    pair<int, int> p, q;

    while (!pq.empty())
    {
        p = pq.top();
        pq.pop();
        while (!pq.empty() && pq.top().first <= p.second)
        {
            q = pq.top();
            pq.pop();
            p.second = max(p.second, q.second);
        }
        ans.push_back({p.first, p.second});
    }
    return ans;
}

/* Using Tree Interval: Without sorting */
class IntervalTree
{
public:
    int middle;
    int start, end;
    IntervalTree *left, *right;
    IntervalTree(int s, int e) : start(s), end(e), middle((s + e) / 2)
    {
        this->left = this->right = NULL;
    }
};

void InsertInterval(IntervalTree *node, Interval currentInterval)
{
    if (node == NULL)
        return;

    if (currentInterval.end < node->middle)
    { // add it to left subtree
        if (node->left)
            return InsertInterval(node->left, currentInterval);
        else
        {
            IntervalTree *newnode = new IntervalTree(currentInterval.start, currentInterval.end);
            node->left = newnode;
            return;
        }
    }

    if (currentInterval.start > node->middle)   // add it to right subtree
    { 
        if (node->right)
            return InsertInterval(node->right, currentInterval);
        else
        {
            IntervalTree *newnode = new IntervalTree(currentInterval.start, currentInterval.end);
            node->right = newnode;
            return;
        }
    }

    node->start = min(node->start, currentInterval.start); //overlap with the current interval, then update the current node
    node->end = max(node->end, currentInterval.end);
}

void QueryInterval(vector<Interval> &retV, IntervalTree *node)
{
    //retV is the return vector
    vector<Interval> leftIntervals;
    vector<Interval> rightIntervals;

    bool mergeleft = false; //whether current node merge with any intervals from left child.
    if (node->left)
    {
        //return the merge of all intervals in left child.
        QueryInterval(leftIntervals, node->left);
        //merge left interval with myself.
        MergeLeftInterval(leftIntervals, node, retV, mergeleft);
    }
    if (!mergeleft)
    { //if we did not merge left intervals, add a new one
        Interval newinterval;
        newinterval.start = node->start;
        newinterval.end = node->end;
        retV.push_back(newinterval);
    }
    if (node->right)
    {
        QueryInterval(rightIntervals, node->right);
        MergeRightInterval(rightIntervals, node, retV);
    }
    return;
}

void MergeLeftInterval(vector<Interval> &leftIntervals, IntervalTree *node, vector<Interval> &retV, bool &merged)
{
    for (int i = 0; i < leftIntervals.size(); i++)
    {
        if (leftIntervals[i].end >= node->start)
        {
            Interval newinterval;
            newinterval.start = min(leftIntervals[i].start, node->start);
            newinterval.end = node->end;
            retV.push_back(newinterval);
            merged = true;
            break;
        }
        else
            retV.push_back(leftIntervals[i]);
    }
}

void MergeRightInterval(vector &rightIntervals, IntervalTree *node, vector &retV)
{
    for (int i = 0; i < rightIntervals.size(); i++)
    {
        if (rightIntervals[i].start <= node->end)
        {
            retV[retV.size() - 1].end = max(rightIntervals[i].end, node->end);
        }
        else
        {
            retV.push_back(rightIntervals[i]);
        }
    }
}