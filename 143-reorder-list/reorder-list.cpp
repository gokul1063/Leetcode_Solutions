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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return ;

        ListNode dummyHead;
        dummyHead.next = head;

        ListNode* slow = head;
        ListNode* fast = head;


        // find the middel

        while (fast && fast->next ){
            fast = fast->next->next;
            slow = slow->next;
        }

        // now we are in middel 

        ListNode *prev = nullptr;
        ListNode *head2 = slow->next;
        slow->next = nullptr;

        while (head2){
            ListNode *temp = head2->next;
            head2->next = prev;
            prev = head2;
            head2 = temp;
        }

        // now insertion
        head2 = prev;
        ListNode* head1 = dummyHead.next;
        while (head2 && head1){
            ListNode* temp = new ListNode(head2->val);
            temp->next = head1->next;
            head1->next = temp;
            head1 = temp->next;
            head2 = head2->next;
        }

        head = dummyHead.next;
        
    }
};