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
    int length(ListNode* head){
        ListNode*temp=head;
        int cnt=0;
        while(temp){
            cnt++;
            temp=temp->next;

        }
        return cnt;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int l=length(head);
        if(l<k){
            return head;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* tail=head;
        for(int i=0;i<k;i++){
             ListNode* temp=curr->next;
             curr->next=prev;
             prev=curr;
             curr=temp;
        }
        tail->next=reverseKGroup(curr,k);
        return prev;
        
    }
};