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
    ListNode * ans;
    void solve(ListNode* p){
        if(p->next==NULL){
            ans=p;
            return;

        }
        solve(p->next);
        p->next->next=p;
        p->next=NULL;

    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        solve(head);
        return ans;
        
        
    }
};