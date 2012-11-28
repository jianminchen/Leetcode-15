/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int add = 0;
        ListNode* prev = 0 , *ans = 0;
        while( l1 || l2 )
        {
            int sum = add;
            if(l1)
                sum += l1->val;
            if(l2)
                sum += l2->val;
            ListNode* tmp = new ListNode(sum % 10);
            add = sum / 10;
            if(prev == 0)
            {
                prev = tmp;
                ans = tmp;
            }
            else
            {
                prev->next = tmp;
                prev = tmp;
            }
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        if(add)
        {
            prev->next = new ListNode(1);
        }
        return ans;
    }
};