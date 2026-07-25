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
    ListNode* rotateRight(ListNode* head, int k) {
        // find length 
        if (head == nullptr || head->next == nullptr || k == 0) return head;
        int len = 0;;
        ListNode* temp = head ;
        while(temp){
            len++;
            temp = temp->next ;
        }
        if(k%len == 0) return head ; // same answer 


        // find tail node and attach it to head 
        temp = head ;
        while(temp->next){
            temp = temp->next ;
        }
        ListNode* last = temp ;
        last->next = head ;


        // find n - kth node 
        temp = head ;
        int index = len - (k%len) ; // 5 - 1 = 4 
        ListNode* tobelast = nullptr ;
        index--;
        while(temp && index > 0){
            index--;
            temp = temp->next ;
        }
        ListNode* newhead = temp->next ;
        tobelast = temp ;
        tobelast->next = nullptr ;
        return newhead ;
    }
};