class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* fst = head,*snd = head ,*prev = 0;
        while(n--)
        {
            snd = snd->next;
        }
        while(snd)
        {
            prev = fst;
            snd = snd -> next;
            fst = fst -> next;
        }
        if(prev == 0) return head->next;
        else prev->next = fst->next;
        return head;
    }
};