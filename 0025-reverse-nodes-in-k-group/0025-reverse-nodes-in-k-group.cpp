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
    int length(ListNode*&head){
        int count=0;
        ListNode*temp=head;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        int l=length(head);
        if(k>l){
            return head;
        }

            ListNode*prev=NULL;
            ListNode*curr=head;
            ListNode*forward;
            int count=0;
            while(count<k){
                forward=curr->next;
                curr->next=prev;
                prev=curr;
                curr=forward;
                count++;
            }
            if(forward!=NULL){
                head->next=reverseKGroup(forward,k);

            }
          return prev;
               
    }
};