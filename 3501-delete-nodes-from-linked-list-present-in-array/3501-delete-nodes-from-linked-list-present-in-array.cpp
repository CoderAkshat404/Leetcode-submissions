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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> s;
        for(auto i:nums){
            s.insert(i);
        }
        ListNode* h=new ListNode();
        ListNode* x=new ListNode();
        ListNode* temp=head;
        while(temp!=NULL){
            if(s.find(temp->val)==s.end()){
                if(h->val==0){
                   ListNode* a=new ListNode(temp->val);
                
                   x=a;
                   h=x;

                }
                else{
                    ListNode* a=new ListNode(temp->val);
                    x->next=a;
                    x=x->next;
                }
            }
            temp=temp->next;
        }
        return h;
        
    }
};