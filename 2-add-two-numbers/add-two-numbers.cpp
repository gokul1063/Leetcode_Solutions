/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        if (!l1 && !l2)
            return nullptr;
        
        ListNode* dummy = new ListNode();
        ListNode* dummy2 = dummy;
        int rem = 0;

        while (l1 && l2) {
            int val = rem + l1->val + l2->val;
            if (val >= 10){
                rem = val / 10;
                val = val % 10;
            } else {
                rem = 0;
            }

            ListNode* temp = new ListNode(val);
            dummy->next = temp;
            l1 = l1->next;
            l2 = l2->next;
            dummy = dummy->next;

        }

        while (l1) {
            int val = rem + l1->val;
            if (val >= 10){
                rem = val / 10;
                val = val % 10;
            } else {
                rem = 0;
            }

            ListNode* temp = new ListNode(val);
            dummy->next = temp;
            l1 = l1->next;
            dummy = dummy->next;
        }


        while (l2) {
            int val = rem + l2->val;
            if (val >= 10){
                rem = val / 10;
                val = val % 10;
            } else {
                rem = 0;
            }

            ListNode* temp = new ListNode(val);
            dummy->next = temp;
            l2 = l2->next;
            dummy = dummy->next;
        }

        if (rem > 0){
            ListNode* temp = new ListNode(rem);
            dummy->next = temp;
            dummy = temp;
        }

        return dummy2->next;
    }
};