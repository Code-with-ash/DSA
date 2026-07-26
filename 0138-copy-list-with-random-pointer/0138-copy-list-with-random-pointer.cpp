/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // insert node in between
        Node* temp = head ;
        while(temp){
            Node* newnode = new Node(temp->val) ;
            newnode->next = temp->next ;
            temp->next = newnode ;
            temp = temp->next->next ;
        }

        temp = head ;
        // connecting the random pointers 
        while(temp){
            Node* copynode = temp->next ;
            if(temp->random){
                copynode->random = temp->random->next;
            }
            else{
                  copynode->random = nullptr ;
            }
            temp = temp->next->next ;
        }
        Node* dummy = new Node(-1);
        temp = head;
        Node* res = dummy ;
        while(temp){
            res->next = temp->next ;
            temp->next = temp->next->next ;
            temp = temp->next ;
            res = res->next ;
        }
        return dummy->next ;
    }
};