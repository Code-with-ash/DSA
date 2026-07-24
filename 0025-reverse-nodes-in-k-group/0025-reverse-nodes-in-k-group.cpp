class Solution {
public:
    // Move k-1 steps forward to find the kth node from `temp`
    ListNode* findkth(ListNode* temp, int k) {
        k--;
        while (temp != nullptr && k > 0) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    // Standard iterative reversal, returns new head of reversed segment
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevTail = nullptr; // tail of the previously-reversed group
        ListNode* newHead = nullptr;  // final head of the answer

        while (temp) {
            ListNode* kthnode = findkth(temp, k);

            if (kthnode == nullptr) {
                // fewer than k nodes left: leave them as-is, attach and stop
                if (prevTail) prevTail->next = temp;
                break;
            }

            ListNode* nextnode = kthnode->next; // start of the next group
            kthnode->next = nullptr;             // detach this group

            ListNode* groupHead = reverse(temp);  // temp becomes tail after reversal

            if (temp == head) {
                newHead = groupHead;   // first group becomes the new list head
            } else {
                prevTail->next = groupHead; // link previous group's tail to this new head
            }

            prevTail = temp;   // temp is now the tail of this reversed group
            temp = nextnode;   // move on to next group
        }

        return newHead ? newHead : head;
    }
};