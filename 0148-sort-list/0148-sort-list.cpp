class Solution {
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while (temp1 && temp2) {
            if (temp1->val < temp2->val) {
                curr->next = temp1;
                curr = temp1;
                temp1 = temp1->next;
            } else {
                curr->next = temp2;
                curr = temp2;
                temp2 = temp2->next;
            }
        }
        if (temp1) curr->next = temp1;
        else curr->next = temp2;

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }

    ListNode* findMiddle(ListNode* node) {
        ListNode* slow = node;
        ListNode* fast = node;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergesort(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head; // already sorted

        ListNode* mid = findMiddle(head);       // find middle
        ListNode* nextnode = mid->next;
        mid->next = nullptr;                    // split into two halves

        ListNode* left = mergesort(head);        // recursively sort left half
        ListNode* right = mergesort(nextnode);   // recursively sort right half

        return merge(left, right);               // merge sorted halves and return
    }

public:
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};