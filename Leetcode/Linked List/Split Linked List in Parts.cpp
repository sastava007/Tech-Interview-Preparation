/*
    Given a LL of length N, split it into K parts of almost equal size and at max two list should differ by just 1 node. 
    And if K>N then populate the remaining slots with NULL node.

    Example:
        [1, 2, 3], k = 5   =>    [[1],[2],[3],[],[]]
        [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3   =>  [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]

    TC: O(N+K) & Space: O(K)
*/

class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *root, int k)
    {
        ListNode *curr = root;
        vector<ListNode *> ans;

        int n = 0, remainder, remaining;
        while (curr)
        {
            curr = curr->next;
            n++;
        }
        remainder = n % k;
        for (int i = 0; i < k; i++)
        {
            curr = root;
            if (i < remainder)
                root = split(curr, n / k, true);
            else
                root = split(curr, n / k, false);
            ans.push_back(curr);
        }
        return ans;
    }
private:
    ListNode *split(ListNode *head, int n, bool extraNode) // split() is similar to how we had in sort LL to split a small part of linked list of containing N nodes
    {
        for (int i = 1; head && i < n; i++)
            head = head->next;

        if (n != 0 && head && extraNode)
            head = head->next;

        ListNode *temp = NULL;
        if (head)
        {
            temp = head->next;
            head->next = NULL;
        }
        return temp;
    }
};

/* Elegant Code */
class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *root, int k)
    {
        vector<ListNode *> parts(k, NULL);
        int len = 0;
        for (ListNode *node = root; node; node = node->next)
            len++;

        int n = len / k, r = len % k;       // n : minimum guaranteed part size; r : extra nodes spread to the first r parts

        ListNode *node = root, *prev = NULL;
        for (int i = 0; node && i < k; i++, r--)
        {
            parts[i] = node;
            for (int j = 0; j < n + (r > 0); j++)
            {
                prev = node;
                node = node->next;
            }
            prev->next = NULL;
        }
        return parts;
    }
};