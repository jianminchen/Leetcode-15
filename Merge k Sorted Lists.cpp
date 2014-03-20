/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
typedef pair<int,ListNode* > int_ListNode_pair;
typedef priority_queue<int_ListNode_pair, vector<int_ListNode_pair> , greater<int_ListNode_pair> > PQ;

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int K = lists.size();
        PQ q;
        for(int i = 0 ; i < K ; i ++)
        {
            if(lists[i] != NULL)
                q.push( int_ListNode_pair(lists[i]->val, lists[i]));
        }
        ListNode* head = NULL, *curNode = NULL;
        while(!q.empty())
        {
            int_ListNode_pair p = q.top();
            q.pop();

            if(head == NULL)
            {
                head = p.second;
            }
            else
            {
                curNode->next = p.second;
            }
            curNode = p.second;
            if(curNode->next != NULL)
            {
                q.push(int_ListNode_pair(curNode->next->val,curNode->next) );
            }
        }
        return head;
    }
};