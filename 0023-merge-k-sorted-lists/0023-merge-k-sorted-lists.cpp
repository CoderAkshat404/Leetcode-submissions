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
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; 
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) pq.push(lists[i]);
        }
        while (!pq.empty()) {
            if (head == NULL) {
                head = pq.top();
                tail = pq.top();
                pq.pop();
                if (tail->next) {
                    pq.push(tail->next);
                }

            } else {
                tail->next = pq.top();
                pq.pop();
                tail = tail->next;
                if (tail->next) {
                    pq.push(tail->next);
                }
            }
        }
        return head;
    }
};
