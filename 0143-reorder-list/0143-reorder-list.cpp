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
    void reorderList(ListNode* head) {
        vector<ListNode*> node;
        ListNode*temp=head;
        while(temp!=NULL){
            node.push_back(temp);
            temp=temp->next;
        }
        int i=0;
        int j=node.size()-1;
        vector<ListNode*> mod;
        while(i<=j){
            if(i==j){
                mod.push_back(node[i]);
            }
            else{
                mod.push_back(node[i]);
                mod.push_back(node[j]);
            }
            i++;
            j--;
        }
        ListNode*curr=NULL;
        curr=head;
        for(int i=1;i<mod.size();i++){
            ListNode*newnode=new ListNode(mod[i]->val);
            curr->next=newnode;
            curr=newnode;
        }  
    }
};