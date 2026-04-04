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
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        int n=lists.size();
        for(int i=0;i<n;i++){
            if(lists[i]){
                
                pq.push({lists[i]->val,lists[i]});
            }
        }
        
        ListNode* head=NULL;
        ListNode* temp=NULL;
        while(!pq.empty()){
            int x=pq.top().first;
            ListNode* ptr=pq.top().second;
            pq.pop();
            if(ptr->next){
               
                ptr=ptr->next;
                pq.push({ptr->val,ptr});
            }
            if(head==NULL){
                ListNode* curr=new ListNode(x);
                head=curr;
                temp=curr;
            }
            else{
                ListNode* curr=new ListNode(x);
                
                temp->next=curr;
                temp=temp->next;
            }
        }
        return head;

        

        
    }
};