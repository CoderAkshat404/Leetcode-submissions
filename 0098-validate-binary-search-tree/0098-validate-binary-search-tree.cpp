/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root,long long ll,long long ul){
        if(root==NULL){
            return true;
        }
        if(root->val<=ll || root->val>=ul){
            return false;
        }
        return solve(root->left,ll,root->val) && solve(root->right,root->val,ul);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,-1e12,1e12);
        
    }
};