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
        ListNode* temp = new ListNode((l1->val + l2->val) % 10);
        int carry = (l1->val + l2->val) / 10;
        ListNode* t1 = l1->next;
        ListNode* t2 = l2->next;
        ListNode* head = temp;
        while (t1 || t2) {
        int sum = carry ;
            if (t1) sum += t1->val;
            if (t2) sum += t2->val;
            carry = sum / 10;
            ListNode* x = new ListNode(sum % 10);
            temp->next = x;
            temp = x;
            if(t1) t1 = t1->next;
            if(t2) t2 = t2->next;
        }
        if (carry>0) {
            ListNode* carries = new ListNode(carry);
        temp->next = carries;
        }
        return head;
    }
};