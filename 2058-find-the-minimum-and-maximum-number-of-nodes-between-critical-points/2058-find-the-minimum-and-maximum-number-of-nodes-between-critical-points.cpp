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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> points;
        ListNode* curr=head;
        ListNode* prev=NULL;
        int cnt=0;
        while(curr->next){
            cnt++;
            ListNode* temp=curr->next;
            if(prev){
                if((prev->val > curr->val )&& (temp->val > curr-> val) ){
                    points.push_back(cnt);
                }
                if((prev->val < curr->val )&& (temp->val < curr-> val) ){
                    points.push_back(cnt);
                }
            }
            prev=curr;
            curr=temp;
        }
        int mini=1e9;
        if(points.size()<=1){
            return {-1,-1};
        }
        for(int i=1;i<points.size();i++){
            mini=min(mini,(points[i]-points[i-1]));
        }
        return {mini,points.back()-points[0]};
        
    }
};