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
    TreeNode* ans;
    void solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if((p->val>=root->val && q->val<=root->val) || (p->val<=root->val && q->val>=root->val)){
            ans=root;
            return ;
        }
        if((p->val<root->val && q->val<root->val)){
            solve(root->left,p,q);
        }
        if(p->val>root->val && q->val>root->val){
            solve(root->right,p,q);
        }

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root,p,q);
        
        return ans;
        
    }
};