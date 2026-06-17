class Solution {
public:
    int pairSum(ListNode* head) {

        vector<int> orig;

        ListNode* temp = head;
        while(temp){
            orig.push_back(temp->val);
            temp = temp->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        ListNode* head2 = prev;
        int maxi = 0;
        int i = 0;

        while(head2 != NULL){
            maxi = max(maxi, orig[i] + head2->val);
            i++;
            head2 = head2->next;
        }

        return maxi;
    }
};