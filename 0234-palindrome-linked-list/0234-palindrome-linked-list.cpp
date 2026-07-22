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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;
        ListNode* slow = head ;
        ListNode* fast = head ;
        while(fast->next && fast->next->next){
            slow = slow->next ;
            fast = fast->next->next ;
        }

        // now slow is on just before the middle element
        ListNode* prev = nullptr ;
        ListNode* curr = slow->next ; // new head 
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev ;
            prev = curr ;
            curr = next ;
        }
        // now head it at prev 
        ListNode* newHead = prev ;
        // now we stand on real head and newHead and we compare 
        ListNode* first = head ;
        ListNode* second = newHead ;
        while(first && second){
            if(first->val != second->val) return false;
            first = first->next ;
            second = second->next ;
        }
        return true;
    }
};