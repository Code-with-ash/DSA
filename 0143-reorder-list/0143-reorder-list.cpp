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
    private:
    ListNode* reverseit(ListNode* head){
        ListNode* prev = nullptr ;
        ListNode* temp = head ;
        ListNode* curr = head ;
        while(temp){
            temp = temp->next ;
            curr->next = prev ;
            prev = curr ;
            curr = temp ;
        }
        return prev ;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head ;
        ListNode* fast = head->next ;
        while(fast && fast->next){
          slow = slow->next ;
          fast = fast->next->next ;  
        }
        ListNode* newhead = reverseit(slow->next);
        slow->next = nullptr ;
        slow = head ;
        ListNode* temp1 = slow ;
        ListNode* temp2 = newhead ;
        while(slow && newhead){
            temp1 = temp1->next ;
            temp2= temp2->next ;
            slow->next = newhead;
            newhead->next = temp1;
            slow = temp1 ;
            newhead = temp2 ;
        }
    }
};