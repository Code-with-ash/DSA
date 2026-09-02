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
    // if (temp1->val > temp2->val) {
    //         head = temp2 ;
    //         temp2 = temp2 ->next ;
    //     } else {
    //         head = temp1 ;
    //         temp1 = temp1->next ;
    //     }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr)
            return nullptr;
        if (list2 == nullptr)
            return list1;
        if (list1 == nullptr)
            return list2;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* curr = nullptr;
        ListNode* prev = nullptr;
        ListNode* head = nullptr;

        if (temp1->val < temp2->val) {
            head = temp1;
            prev = temp1;
            temp1 = temp1->next;
        } else {
            head = temp2;
            prev = temp2;
            temp2 = temp2->next;
        }
        while (temp1 && temp2) {
            if (temp1->val < temp2->val) {
                curr = temp1->next;
                prev->next = temp1;
                prev = temp1;
                temp1 = curr;
            } else {
                curr = temp2->next;
                prev->next = temp2;
                prev = temp2;
                temp2 = curr;
            }
        }
        if (temp1)
            prev->next = temp1;
        else
            prev->next = temp2;
        return head;
    }
};