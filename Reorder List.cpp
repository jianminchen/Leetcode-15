class Solution
{
public:
    ListNode *start;
    bool finish;
    void dfs(ListNode *cur)
    {
        if(cur == NULL) return;
        dfs(cur->next);
		if(finish) return;
        if(start->next == cur || start == cur)
        {
            cur->next = NULL;
            finish = true;
            return;
        }
        cur->next = start->next;
        start->next = cur;
        start = cur->next;

    }
    void reorderList(ListNode *head)
    {
        start = head;
		finish = false;
        dfs(head);
    }
};