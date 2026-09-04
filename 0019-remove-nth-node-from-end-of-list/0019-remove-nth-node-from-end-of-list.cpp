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
    private :
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // reverse the ll
        ListNode* newhead = reverseit(head);

        // find the nth element 
        if(n==1) return reverseit(newhead->next) ;
        ListNode* temp = newhead ;
        ListNode* prev = nullptr ;

        while(n-1>0){
            prev = temp ;
            temp = temp->next ;
            n--;
        }
        prev ->next = temp->next ;
        delete(temp);

        return reverseit(newhead);
    }
};