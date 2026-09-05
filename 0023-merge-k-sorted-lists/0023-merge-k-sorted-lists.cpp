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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < k; i++) {
           if (lists[i])
                pq.push(lists[i]);
        }
          if (pq.empty())
            return nullptr;
        ListNode* head = pq.top();
        pq.pop();
        ListNode* temp = head;
        if (head->next)
            pq.push(head->next);
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            temp->next = node;
            temp = node;
            if (node->next)
                pq.push(node->next);
        }
        return head;
    }
};