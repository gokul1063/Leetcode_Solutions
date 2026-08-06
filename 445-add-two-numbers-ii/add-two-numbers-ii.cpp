class Solution {
public:
    ListNode* reverse(ListNode* l1){

        ListNode* prev1 = nullptr;
        

        // reverse l1 

        while (l1){
            ListNode* temp = l1->next;
            l1->next = prev1;
            prev1 = l1;
            l1 =  temp;
        }

        

        return prev1;
    }

    void print(ListNode* l1){
        ListNode* temp = l1;

        while (temp){
            cout << "val : " << temp->val << endl;
            temp = temp->next;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       if (!l1)
            return l2;
        if (!l2)
            return l1;
        if (!l1 && !l2)
            return nullptr;
        

        l1 = reverse(l1);
        l2 = reverse(l2);

        print(l1);
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

        ListNode* result = reverse(dummy2->next);
        return result;
    }
};