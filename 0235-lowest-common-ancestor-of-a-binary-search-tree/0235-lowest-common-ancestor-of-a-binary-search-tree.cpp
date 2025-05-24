/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void findans(TreeNode* root,TreeNode* &ans,int ll,int ul){
        if(root==NULL){
            return;
        }
        if(root->val>=ll && root->val<=ul){
            ans=root;
            return;
        }
        if(root->val<ll){
            findans(root->right,ans,ll,ul);
        }
        else{
            findans(root->left,ans,ll,ul);

        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int ll=min(p->val,q->val);
        int ul=max(p->val,q->val);
        TreeNode* ans=NULL;
        findans(root,ans,ll,ul);
        return ans;
        
    }
};